
#ifndef MODEL_LIVEPOST_H
#define MODEL_LIVEPOST_H

#include <string>
#include <map>
#include <set>
#include <algorithm> //for_each
#include <iostream>
#include <chrono>
#include <vector>

namespace LivePostsModel
{

  enum class PostStatus
  {
    Draft,
    PendingModeration,
    Live,
    Rejected
  };

  // Define a struct to encapsulate Post table insert, update and query
  struct Post
  {
    int id = 0;
    std::string title;
    std::string content;
    std::string draftTitle;
    std::string draftContent;
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
    PostStatus status{PostStatus::Draft};
    bool allocated = false;

    Post() = default;
  };

  struct PostCreate
  {
    std::string title;
    std::string content;
    std::string wsId;

    PostCreate() = default;
  };

  struct PostUpdate
  {
    std::string title;
    std::string content;
    std::string wsId;

    PostUpdate() = default;
  };

  struct PostStage
  {
    std::string title;
    std::string wsId;

    PostStage() = default;
  };

  struct User
  {
    int id = 0;
    std::string authUserId;
    std::string authUserEmail;
    std::string name;

    User() = default;
  };

  struct UserCreate
  {
    std::string authUserId;
    std::string authUserEmail;
    std::string wsId;

    UserCreate() = default;
  };

  struct Moderation
  {
    std::string id;
    std::string wsId;
    uint64_t seq{0};
    std::string value;

    Moderation() = default;
  };

  struct ModerationToken
  {
    std::vector<int64_t> input_ids;
    std::vector<int64_t> attention_mask;
  };

  struct ModerationLogits
  {
    std::vector<float> logits;
  };

  namespace Validate
  {
    bool Posts(const LivePostsModel::Post &o);
    bool PostCreate(const LivePostsModel::PostCreate &o);
    bool PostUpdate(const LivePostsModel::PostUpdate &o);
    bool PostStage(const LivePostsModel::PostStage &o);
    bool Users(const LivePostsModel::User &o);
    bool UserCreate(const LivePostsModel::UserCreate &o);
    bool Moderation(const LivePostsModel::Moderation &o);
    bool ModerationToken(const LivePostsModel::ModerationToken &o);
    bool ModerationLogits(const LivePostsModel::ModerationLogits &o);
  }

}
#endif // MODEL_LIVEPOST_H
