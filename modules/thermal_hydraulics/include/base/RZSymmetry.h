#pragma once

#include "InputParameters.h"

#include "libmesh/vector_value.h"

/**
 * Interface class for enabling objects to be RZ symmetric about arbitrary axis
 */
class RZSymmetry
{
public:
  RZSymmetry(const MooseObject * moose_object, const InputParameters & parameters);

protected:
  virtual Real computeCircumference(const RealVectorValue & pt);

  /// A point on the axis of symmetry
  RealVectorValue _axis_point;
  /// The direction of the axis of symmetry
  const RealVectorValue & _axis_dir;
  /// Radial offset of the axis of symmetry
  const Real & _offset;

public:
  static InputParameters validParams();
};