//=============================================================================
//    Copyright (C) 2021-2022 Wageningen University - All Rights Reserved
//                     Author: Gonzalo Mier
//                        BSD-3 License
//=============================================================================

#include <steering_functions/dubins_state_space/dubins_state_space.hpp>
#include "fields2cover/path_planning/steer_to_path.hpp"
#include "fields2cover/path_planning/dubins_curves.h"

namespace f2c {
namespace pp {

DubinsCurves::DubinsCurves(const F2CRobot& _params) {
  setRobotParams(_params);
}

F2CPath DubinsCurves::createSimpleTurn(double _dist_start_pos,
    double _start_angle, double _end_angle) {
  steer::State start, end;

  start.x = 0.0;
  start.y = 0.0;
  start.theta = _start_angle;
  start.kappa = 0.0;
  start.d = 0;

  end.x = _dist_start_pos;
  end.y = 0.0;
  end.theta = _end_angle;
  end.kappa = 0.0;
  end.d = 0;

  Dubins_State_Space ss(
      robot.max_icc,
      discretization_,
      true);
  return steerStatesToPath(ss.get_path(start, end),
      robot.max_vel ? *robot.max_vel : robot.cruise_speed);
}

}  // namespace pp
}  // namespace f2c
