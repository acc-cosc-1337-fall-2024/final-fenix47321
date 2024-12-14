//
#ifndef COUT_OUT_PHASE_H
#define COUT_OUT_PHASE_H

#include "phase.h"

class ComeOutPhase : public Phase {
public:
    RollOutcome get_outcome(Roll* roll) override;
};


#endif COUT_OUT_PHASE_H