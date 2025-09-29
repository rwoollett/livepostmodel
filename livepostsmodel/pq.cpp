#include "pq.h"
#include <unordered_map>
#include "timestamp.h"

#ifdef NDEBUG
#define D(x)
#else
#define D(x) x
#endif

#ifdef LIBPQ_FOUND
namespace LivePostsModel::PG
{
  std::unordered_map<std::string, int> mapFieldCols(PGresult *res, int nCols)
  {
    std::unordered_map<std::string, int> fieldColumns{};
    for (int i = 0; i < nCols; i++)
    {
      const char *field_name = PQfname(res, i);
      fieldColumns[std::string(field_name)] = i;
    }
    return fieldColumns;
  };

  auto const getStringFromResRowByKey = [](
                                            PGresult *res,
                                            int rowIndex,
                                            const std::unordered_map<std::string, int> &fieldColumns,
                                            const std::string &key) -> std::string
  {
    auto it = fieldColumns.find(key);
    if (it == fieldColumns.end())
      throw std::string("Field not matched for " + key);
    return std::string(PQgetvalue(res, rowIndex, fieldColumns.at(key)));
  };

  LivePostsModel::Post Posts::fromPGRes(PGresult *res, int nCols, int rowIndex)
  {
    LivePostsModel::Post post{};
    try
    {
      auto fieldColumns = mapFieldCols(res, nCols);
      auto const getString = [res, rowIndex, &fieldColumns](const std::string &key)
      {
        return getStringFromResRowByKey(res, rowIndex, fieldColumns, key);
      };

      post.id = std::atoi(getString("id").c_str());
      post.title = getString("title");
      post.content = getString("content");
      post.userId = std::atoi(getString("userId").c_str());
      post.userName = getString("userName");
      post.date = getString("date");
      auto tpOptD = LivePostsModel::parseDate(getString("date"));
      if (tpOptD)
        post.tpDate = *tpOptD;
      post.thumbsUp = std::atoi(getString("thumbsUp").c_str());
      post.hooray = std::atoi(getString("hooray").c_str());
      post.heart = std::atoi(getString("heart").c_str());
      post.rocket = std::atoi(getString("rocket").c_str());
      post.eyes = std::atoi(getString("eyes").c_str());
      post.live = (getString("live") == "t");
      post.allocated = (getString("allocated") == "t");

    }
    catch (const std::string &e)
    {
      throw e;
    }
    catch (...)
    {
      throw "error in fromPQRes";
    }

    return post;
  }

  
  LivePostsModel::User Users::fromPGRes(PGresult *res, int nCols, int rowIndex)
  {
    LivePostsModel::User user{};
    try
    {
      auto fieldColumns = mapFieldCols(res, nCols);
      auto const getString = [res, rowIndex, &fieldColumns](const std::string &key)
      {
        return getStringFromResRowByKey(res, rowIndex, fieldColumns, key);
      };

      user.id = std::atoi(getString("id").c_str());
      user.authId = getString("authId");
      user.name = getString("name");
    }
    catch (const std::string &e)
    {
      throw e;
    }
    catch (...)
    {
      throw "error in fromPQRes";
    }

    return user;
  }

} // namespace Model::PG
#endif // LIBPQ_FOUND
