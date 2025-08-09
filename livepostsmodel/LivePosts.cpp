#include "LivePosts.h"

namespace LivePostsModel
{

  bool Validate::Post(const LivePostsModel::Post &o)
  {
    return !(o.title.empty() || o.content.empty() || o.user.empty() || o.date.empty());
  }

}