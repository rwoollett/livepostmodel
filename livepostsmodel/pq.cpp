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

  LivePostsModel::Post Post::fromPGRes(PGresult *res, int nCols, int rowIndex)
  {
    LivePostsModel::Post post{};
    try
    {
      auto fieldColumns = mapFieldCols(res, nCols);
      auto const getString = [res, rowIndex, &fieldColumns](const std::string &key)
      {
        return getStringFromResRowByKey(res, rowIndex, fieldColumns, key);
      };

      post.id = getString("id");
      post.title = getString("title");
      post.content = getString("content");
      post.user = getString("user");
      post.date = getString("date");
      auto tpOptD = LivePostsModel::parseDate(getString("date"));
      if (tpOptD)
        post.tpDate = *tpOptD;
      post.thumbsUp = std::atoi(getString("thumbsUp").c_str());
      post.hooray = std::atoi(getString("hooray").c_str());
      post.heart = std::atoi(getString("heart").c_str());
      post.rocket = std::atoi(getString("rocket").c_str());
      post.eyes = std::atoi(getString("eyes").c_str());
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

} // namespace Model::PG
#endif // LIBPQ_FOUND
