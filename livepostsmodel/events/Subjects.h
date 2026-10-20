
#ifndef EVENT_LIVEPOST_SUBJECTS_H
#define EVENT_LIVEPOST_SUBJECTS_H

#include <string>
#include <map>
#include <string_view>

namespace LivePostsEvents
{

  enum class Subject
  {
    Invalid = -1,
    PostCreate,
    PostUpdate,
    PostPublished,
    PostStage,
    ModerateJob,
    ModerateResult
  };

  static const std::map<Subject, std::string_view> SubjectNames = {
      {Subject::PostCreate, "liveposts_post_Create"},          // Producer stream name
      {Subject::PostUpdate, "liveposts_post_Update"},          // Producer stream name
      {Subject::ModerateJob, "liveposts_moderate_Job"},        // Producer stream name
      {Subject::PostPublished, "liveposts_post_Published"},    // Publish channel name (to specifed wsId)
      {Subject::PostStage, "liveposts_post_Stage"},            // Publish channel name (broadcasted)
      {Subject::ModerateResult, "liveposts_moderate_Result"}}; // Publish channel name (to specifed wsId)

  static const std::map<std::string_view, Subject> SubjectFromNames = {
      {"liveposts_post_Create", Subject::PostCreate},
      {"liveposts_post_Update", Subject::PostUpdate},
      {"liveposts_moderate_Job", Subject::ModerateJob},
      {"liveposts_post_Published", Subject::PostPublished},
      {"liveposts_post_Stage", Subject::PostStage},
      {"liveposts_moderate_Result", Subject::ModerateResult}};

}
#endif // EVENT_LIVEPOST_SUBJECTS_H
