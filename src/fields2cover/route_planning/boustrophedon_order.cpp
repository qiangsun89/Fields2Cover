//=============================================================================
//    Copyright (C) 2021-2022 Wageningen University - All Rights Reserved
//                     Author: Gonzalo Mier
//                        BSD-3 License
//=============================================================================

#include "fields2cover/route_planning/boustrophedon_order.h"

namespace f2c {
namespace rp {

void BoustrophedonOrder::sortSwaths() {
  this->changeStartPoint();
}

}  // namespace rp
}  // namespace f2c

