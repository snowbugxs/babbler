#include "DarcyPressure.h"

registerMooseObject("BabblerApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
    InputParameters params = ADKernelGrad::validParams();
    params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: ");
    return params; 
}
DarcyPressure::DarcyPressure(const InputParameters & parameters)
    :ADKernelGrad(parameters),
    _permeablity(0.8451e-09);
    _viscosity(7.98e-04);
{
}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
    return (_permeablity/_viscosity) * _grad_u[_qp];
}

