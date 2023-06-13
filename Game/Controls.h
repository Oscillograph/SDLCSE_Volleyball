#ifndef CONTROLS_H
#define CONTROLS_H

class class_Controls {
public:
	void setControls(int up1, int left1, int right1,
					 int up2, int left2, int right2){
		P1Up_ = up1;
		P1Left_ = left1;
		P1Right_ = right1;
		P2Up_ = up2;
		P2Left_ = left2;
		P2Right_ = right2;
	}
	
	int P1Up(){
		return P1Up_;
	}
	int P1Left(){
		return P1Left_;
	}
	int P1Right(){
		return P1Right_;
	}
	
	int P2Up(){
		return P2Up_;
	}
	int P2Left(){
		return P2Left_;
	}
	int P2Right(){
		return P2Right_;
	}
	
private:
	int P1Up_;
	int P1Left_;
	int P1Right_;
	
	int P2Up_;
	int P2Left_;
	int P2Right_;
};

#endif
