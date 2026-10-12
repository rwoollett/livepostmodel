#pragma once

#include "LivePosts.h"
#include "PostStatus.h"

#ifdef LIBPQ_FOUND
#include <libpq-fe.h>
namespace LivePostsModel::PG
{
  namespace Posts
  {
    LivePostsModel::Post fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }
  namespace Users
  {
    LivePostsModel::User fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }

} // namespace Model
#endif // LIBPQ_FOUND