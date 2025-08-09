
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
    std::string id;
    std::string title;
    std::string content;
    std::string user;
    std::string date;
    std::chrono::system_clock::time_point tpDate{};
    int thumbsUp;
    int hooray;
    int heart;
    int rocket;
    int eyes;

    Post() = default;
  };

  namespace Validate
  {
    bool Post(const LivePostsModel::Post &o);
  }

}
#endif // MODEL_TTT_H
