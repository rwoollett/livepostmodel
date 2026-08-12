
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
    PostStage,
    ModerateJob,
    ModerateResult
  };

  static const std::map<Subject, std::string_view> SubjectNames = {
      {Subject::PostCreate, "liveposts_post_Create"},          // Producer stream name
      {Subject::PostStage, "liveposts_post_Stage"},            // Publish channel name
      {Subject::ModerateJob, "liveposts_moderate_Job"},        // Producer stream name
      {Subject::ModerateResult, "liveposts_moderate_Result"}}; // Publish channel name

  static const std::map<std::string_view, Subject> SubjectFromNames = {
      {"liveposts_post_Create", Subject::PostCreate},
      {"liveposts_post_Stage", Subject::PostStage},
      {"liveposts_moderate_Job", Subject::ModerateJob},
      {"liveposts_moderate_Result", Subject::ModerateResult}};

}
#endif // EVENT_LIVEPOST_SUBJECTS_H
