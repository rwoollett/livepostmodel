
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
    PostStage
  };

  static const std::map<Subject, std::string_view> SubjectNames = {
      {Subject::PostCreate, "liveposts_post_Create"},
      {Subject::PostStage, "liveposts_post_Stage"}};

  static const std::map<std::string_view, Subject> SubjectFromNames = {
      {"liveposts_post_Create", Subject::PostCreate},
      {"liveposts_post_Stage", Subject::PostStage}};

}
#endif // EVENT_LIVEPOST_SUBJECTS_H
