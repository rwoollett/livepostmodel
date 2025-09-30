
#ifndef MODEL_TTT_H
#define MODEL_TTT_H

#include <string>
#include <map>
#include <set>
#include <algorithm> //for_each
#include <iostream>
#include <chrono>

namespace LivePostsModel
{

  // Define a struct to encapsulate Post table insert, update and query
  struct Post
  {
    int id;
    std::string title;
    std::string content;
    int userId;
    std::string userName;
    std::string date;
    std::chrono::system_clock::time_point tpDate{};
    int thumbsUp;
    int hooray;
    int heart;
    int rocket;
    int eyes;
    bool live{false};
    bool allocated{false};

    Post() = default;
  };

  struct User
  {
    int id;
    std::string authId;
    std::string name;

    User() = default;
  };

  namespace Validate
  {
    bool Posts(const LivePostsModel::Post &o);
    bool Users(const LivePostsModel::User &o);
  }

}
#endif // MODEL_TTT_H
