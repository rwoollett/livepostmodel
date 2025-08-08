#pragma once

#include "LivePosts.h"

#ifdef LIBPQ_FOUND
#include <libpq-fe.h>
namespace LivePostsModel::PG
{
  namespace Game
  {
    LivePostsModel::Game fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }

  namespace PlayerMove
  {
    LivePostsModel::PlayerMove fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }


} // namespace Model
#endif //LIBPQ_FOUND
