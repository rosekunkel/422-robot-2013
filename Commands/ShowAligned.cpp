#include "ShowAligned.h"

ShowAligned::ShowAligned() {
	Requires( antennae );
	Requires( lights );
}

void ShowAligned::Execute() {
	if( antennae->get() ) {
		lights->turnOffRedLight();
		lights->turnOffBlueLight();
		lights->turnOnGreenLight();
	}
	else {
		lights->turnOffGreenLight();
	}
}

bool ShowAligned::IsFinished() {
	return false;
}

