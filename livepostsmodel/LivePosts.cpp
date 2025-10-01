#include "LivePosts.h"

namespace LivePostsModel
{

  bool Validate::Posts(const LivePostsModel::Post &o)
  {
    return !(o.title.empty() || o.content.empty() || o.userId < 0);
  }

  bool Validate::PostStage(const LivePostsModel::PostStage &o)
  {
    return !(o.postId < 0);
  }

  bool Validate::Users(const LivePostsModel::User &o)
  {
    return !(o.name.empty() || o.authId.empty());
  }

}