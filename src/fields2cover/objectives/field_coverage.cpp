//=============================================================================
//    Copyright (C) 2021-2022 Wageningen University - All Rights Reserved
//                     Author: Gonzalo Mier
//                        BSD-3 License
//=============================================================================

#include "fields2cover/objectives/field_coverage.h"

namespace f2c {
namespace obj {

double FieldCoverage::computeCost(
    const F2CCell& poly, const F2CSwaths& swaths) const {
  return computeCost(F2CCells(poly), swaths);
}

double FieldCoverage::computeCost(
    const F2CCells& poly, const F2CSwaths& swaths) const {
  F2CMultiLineString lines;
  for (const auto& s : swaths) {
    lines.addGeometry(s.getPath());
  }

  double area_covered {poly.getCellsInside(
      F2CCells::Buffer(lines, swaths[0].getWidth() / 2.0)).getArea()};
  return area_covered / poly.getArea();
}

bool FieldCoverage::isMinimizing() const {
  return false;
}

}  // namespace obj
}  // namespace f2c

