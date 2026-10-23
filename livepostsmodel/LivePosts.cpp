#include "LivePosts.h"

namespace LivePostsModel
{

  bool Validate::Posts(const LivePostsModel::Post &o)
  {
    return !(o.title.empty() || o.content.empty() || o.userId < 0);
  }

  bool Validate::PostCreate(const LivePostsModel::PostCreate &o)
  {
    return !(o.title.empty() || o.content.empty() || o.wsId.empty());
  }

  bool Validate::PostUpdate(const LivePostsModel::PostUpdate &o)
  {
    return !(o.title.empty() || o.content.empty() || o.wsId.empty());
  }

  bool Validate::PostStage(const LivePostsModel::PostStage &o)
  {
    return !(o.title.empty() || o.wsId.empty());
  }

  bool Validate::Users(const LivePostsModel::User &o)
  {
    return !(o.name.empty() || o.authUserId.empty() || o.authUserEmail.empty());
  }

  bool Validate::Moderation(const LivePostsModel::Moderation &o)
  {
    return !(o.id.empty() || o.wsId.empty() || o.value.empty() || o.seq < 0);
  }

  bool Validate::ModerationToken(const LivePostsModel::ModerationToken &o)
  {
    return !(o.attention_mask.empty() || o.input_ids.empty());
  }

  bool Validate::ModerationLogits(const LivePostsModel::ModerationLogits &o)
  {
    return !(o.logits.empty());
  }

}