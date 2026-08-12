
#ifndef MODEL_LIVEPOST_H
#define MODEL_LIVEPOST_H

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
    int id = 0;
    std::string title;
    std::string content;
    std::string slug;
    int userId = 0;
    std::string userName;
    std::string date;
    std::chrono::system_clock::time_point tpDate{};
    int thumbsUp = 0;
    int hooray = 0;
    int heart = 0;
    int rocket = 0;
    int eyes = 0;
    bool live = false;
    bool allocated = false;

    Post() = default;
  };

  struct PostStage
  {
    int postId = 0;
    std::string title;
    bool live = false;

    PostStage() = default;
  };

  struct User
  {
    int id = 0;
    std::string authId;
    std::string name;

    User() = default;
  };

  struct Moderation
  {
    std::string id;     // id
    std::string userId; // ws user id
    std::string value;

    Moderation() = default;
  };

  namespace Validate
  {
    bool Posts(const LivePostsModel::Post &o);
    bool PostStage(const LivePostsModel::PostStage &o);
    bool Users(const LivePostsModel::User &o);
    bool Moderation(const LivePostsModel::Moderation &o);
  }

}
#endif // MODEL_LIVEPOST_H
