
#ifndef EVENT_LIVEPOST_SUBJECTS_H
#define EVENT_LIVEPOST_SUBJECTS_H

#include <string>
#include <map>
#include <string_view>

/** Flow of streams */
/*
  Create (livepost_svc route)
  ↓
  CreateJob (svc route creates job)
  ↓
  Produce ModerateJob (stream handler produce moderation - can be
                       done with using livepost svc route moderation)
  ↓
  XACK CreateJob

  Then a separate lane at stream handler

  ModerateJob  (stream handler) (produce event PendIngModeration now for user)
  ↓
  ToxicBERT
  ↓
  Pass ?
      ├─ PostStagePublishJob  (produce with poststage or postpromote)
      └─ PostRejectJob        (poduced in moderation route - we get result from moderation currently)

Publish path

  ModerateJob
  ↓
  Moderation Pass
  ↓
  PostStagePublishJob
  ↓
  LivePosts Stage (prerender job ) UpdateJon does PromotePost logic
  ↓
  PostPublished Event
  ↓
  XACK


Reject path

  ModerateJob
  ↓
  Moderation Reject
  ↓
  PostRejectJob
  ↓
  LivePosts Reject
  ↓
  Publish Reject Event
  ↓
  XACK


Refactor to a single event with status -
Now Post have a status field of:-
Draft
PendingModeration
Rejected
Published

and we could have a single event with status ie.
liveposts_post_StatusChanged

{
  "subject": "liveposts_post_StatusChanged",
  "payload": {
    "postId": 123,
    "status": "PendingModeration"
  }
}

to avoid :
PendingModeration
Moderating
Passed
Rejected
StageStarted
StageCompleted
Published becoming seaprate event types (subjects)
*/
namespace LivePostsEvents
{

  enum class Subject
  {
    Invalid = -1,
    PostCreate,
    PostUpdate,
    PostStatusChanged,
    PostStage,
    PostRender,
    ModerateJob,
    ModerateResult,
    UserCreate,
    UserCreated
  };

  static const std::map<Subject, std::string_view> SubjectNames = {
      {Subject::UserCreate, "liveposts_user_Create"},               // Producer stream name
      {Subject::PostCreate, "liveposts_post_Create"},               // Producer stream name
      {Subject::PostUpdate, "liveposts_post_Update"},               // Producer stream name
      {Subject::ModerateJob, "liveposts_moderate_Job"},             // Producer stream name
      {Subject::PostRender, "liveposts_post_Render"},               // Producer stream name
      {Subject::PostStatusChanged, "liveposts_post_StatusChanged"}, // Publish channel name (to specifed wsId)
      {Subject::PostStage, "liveposts_post_Stage"},                 // Publish channel name (broadcasted)
      {Subject::UserCreated, "liveposts_user_Created"},             // Publish channel name (to specifed wsId)
      {Subject::ModerateResult, "liveposts_moderate_Result"}};      // Publish channel name (to specifed wsId)

  static const std::map<std::string_view, Subject> SubjectFromNames = {
      {"liveposts_post_Create", Subject::PostCreate},
      {"liveposts_user_Create", Subject::UserCreate},
      {"liveposts_post_Update", Subject::PostUpdate},
      {"liveposts_moderate_Job", Subject::ModerateJob},
      {"liveposts_post_Render", Subject::PostRender},
      {"liveposts_post_StatusChanged", Subject::PostStatusChanged},
      {"liveposts_post_Stage", Subject::PostStage},
      {"liveposts_user_Created", Subject::UserCreated},
      {"liveposts_moderate_Result", Subject::ModerateResult}};

}
#endif // EVENT_LIVEPOST_SUBJECTS_H
