/***********************************************************************************
Copyright (c) 2017, Michael Neunert, Markus Giftthaler, Markus Stäuble, Diego Pardo,
Farbod Farshidian. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of ETH ZURICH nor the names of its contributors may be used
      to endorse or promote products derived from this software without specific
      prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL ETH ZURICH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***************************************************************************************/


#ifndef CT_CORE_INTERNAL_STEPPERS_CT_H_
#define CT_CORE_INTERNAL_STEPPERS_CT_H_

#include <ct/core/systems/System.h>

namespace ct {
namespace core {
namespace internal {

template <size_t STATE_DIM, typename SCALAR>
class StepperBaseCT
{
public:

    virtual void do_step(
        const StateVector<STATE_DIM, SCALAR>& rhs,
        StateVector<STATE_DIM, SCALAR>& stateInOut,
        const SCALAR time, //is this really required for us?
        const SCALAR dt
        ) = 0;


private:
};


template<size_t STATE_DIM, typename SCALAR>
class StepperEulerCT : public StepperBaseCT<STATE_DIM, SCALAR>
{
public:
    virtual void do_step(
        const StateVector<STATE_DIM, SCALAR>& rhs,
        StateVector<STATE_DIM, SCALAR>& stateInOut,
        const SCALAR time,
        const SCALAR dt
        ) override
    {
        stateInOut += dt * rhs;
    }

private:

};


}
}
}



#endif