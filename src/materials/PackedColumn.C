#include "PackedColumn.h"

registerMooseObject("BabblerApp", PackedColumn); 

InputParameters
PackedColumn::validParams()
{
    InputParameters params = Material::validParams();
    params.addClassDescription("Compute the permeablity of a porous medium made up of packed"
                               "steel spheres of a specified diameter ");
    params.addRangeCheckedParam<Real>(
        "diameter",
        1.0, 
        "(1 <= diameter) & (diameter <= 3)",
        "The diameter of the spheres is used to calculate the permeability");
    params.addRangeCheckedParam<Real>("viscosity",
                                      7.98e-4,
                                      "viscosity != 0.0",
                                      "The dynamic viscosity of the fluid");
    return params;
}

PackedColumn::PackedColumn(const InputParameters & parameters)
  : Material(parameters),
    _diameter(getParam<Real>("diameter")),
    _input_viscosity(getParam<Real>("viscosity")),
    _permeability(declareADProperty<Real>("permeability")),
    _viscosity(declareADProperty<Real>("viscosity"))
{
    std::vector<Real> sphere_size = {1,3};
    std::vector<Real> permeability = {0.8451e-9, 8.968e-9};
    _permeability_interpolation.setData(sphere_size, permeability);
}

void
PackedColumn::computeQpProperties()
{
    _permeability[_qp] = _permeability_interpolation.sample(_diameter);
    _viscosity[_qp] = _input_viscosity; 
}