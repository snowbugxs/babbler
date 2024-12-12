#include "DarcyPressure.h"

registerMooseObject("BabblerApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
    InputParameters params = ADKernelGrad::validParams();
    params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: ");
    params.addRequiredParam<Real>("permeablity", "Permeablity of the porous medium");
    params.addParam<Real>(
        "viscosity", 
        7.98e-4,
        "Viscosity of the fluid");
    return params; 
}
DarcyPressure::DarcyPressure(const InputParameters & parameters)
    :ADKernelGrad(parameters),
    _permeablity(getParam<Real>("permeablity")),
    _viscosity(getParam<Real>("viscosity"))
{
}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
    return (_permeablity/_viscosity) * _grad_u[_qp];
}

