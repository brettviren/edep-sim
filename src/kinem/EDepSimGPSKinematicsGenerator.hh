#ifndef EDepSim_GPSKinematicsGenerator_hh_Seen
#define EDepSim_GPSKinematicsGenerator_hh_Seen

#include <globals.hh>
#include <G4LorentzVector.hh>

#include "kinem/EDepSimVKinematicsGenerator.hh"

class G4Event;
class G4VPrimaryGenerator;

/// A base class for primary generator classes used in the EDepSim::.  This is
/// used by the EDepSim::UserPrimaryGeneratorAction to generate particles which
/// will be tracked by the G4 simulation.
namespace EDepSim {class GPSKinematicsGenerator;}
class EDepSim::GPSKinematicsGenerator : public EDepSim::VKinematicsGenerator {
public:
    GPSKinematicsGenerator(const G4String& name, 
                                G4VPrimaryGenerator* gps);
    virtual ~GPSKinematicsGenerator();

    /// Add a primary vertex to the event.  
    virtual bool GeneratePrimaryVertex(G4Event* evt,
                                       G4LorentzVector& position);

    /// Return the mean event rate per mass per 10^21 pot at a particular
    /// position and in a particular material.
    virtual double EventRate(const G4ThreeVector& pos,
                             const G4Material& material) {
        return 1.0/kg;
    }

private:
    G4VPrimaryGenerator* fGenerator;
};
#endif
