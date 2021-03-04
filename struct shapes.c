

extern struct Shape {
    int row1;
    int block1;

    int row2;
    int block2;

    int row3;
    int block3;

    int row4;
    int block4;

    int bottom_cube;
    int right_cube;
    int left_cube;

};


    //Shape O
	struct Shape O;
	//Cube 1
	O.row1 = 1;
	O.block1 = 6;
	//Cube 2
	O.row2 = 1;
	O.block2 = 5;
	//Cube3
	O.row3 = 2;
	O.block3 = 6;
	//Cube 4
	O.row4 = 2;
	O.block4 = 5;

    //Bottom, left, right cubes
    O.bottom_cube = 2;
    O.left_cube = 6;
    O.right_cube = 5;

	//Shape L
	struct Shape L0;
	//Cube 1
	L0.row1 = 1; 
	L0.block1 = 6;
	//Cube 2
	L0.row2 = 2;
	L0.block2 = 6;
	//Cube 3
	L0.row3 = 3;
	L0.block3 = 6;
	//Cube 4
	L0.row4 = 3;
	L0.block4 = 5;

    //Bottom, left, right cubes
    L0.bottom_cube = 3;
    L0.left_cube = 6;
    L0.right_cube = 5;

	struct Shape L1;
	//Cube 1
	L1.row1 = 1; 
	L1.block1 = 6;
	//Cube 2
	L1.row2 = 2;
	L1.block2 = 6;
	//Cube 3
	L1.row3 = 3;
	L1.block3 = 6;
	//Cube 4
	L1.row4 = 3;
	L1.block4 = 5;

     //Bottom, left, and right cubes
    L1.bottom_cube = 3;
    L1.left_cube = 6;
    L1.right_cube = 5;
	
	struct Shape L2;
	//Cube 1
	L2.row1 = 1; 
	L2.block1 = 6;
	//Cube 2
	L2.row2 = 1;
	L2.block2 = 5;
	//Cube 3
	L2.row3 = 1;
	L2.block3 = 4;
	//Cube 4
	L2.row4 = 2;
	L2.block4 = 6;

    //Bottom, left, and right cubes
    L2.bottom_cube = 2;
    L2.left_cube = 6;
    L2.right_cube = 4;

	struct Shape L3;
	//Cube 1
	L3.row1 = 1; 
	L3.block1 = 6;
	//Cube 2
	L3.row2 = 1;
	L3.block2 = 5;
	//Cube 3
	L3.row3 = 2;
	L3.block3 = 5;
	//Cube 4
	L3.row4 = 3;
	L3.block4 = 5;

     //Bottom, left, and right cubes
    L3.bottom_cube = 3;
    L3.left_cube = 6;
    L3.right_cube = 5;

	//Shape I
	struct Shape I0;
	//Cube 1
	I0.row1 = 1; 
	I0.block1 = 7;
	//Cube 2
	I0.row2 = 1;
	I0.block2 = 6;
	//Cube 3
	I0.row3 = 1;
	I0.block3 = 5;
	//Cube 4
	I0.row4 = 1;
	I0.block4 = 4;

     //Bottom, left, and right cubes
    I0.bottom_cube = 1;
    I0.left_cube = 7;
    I0.right_cube = 4;

	struct Shape I1;
	//Cube 1
	I1.row1 = 1; 
	I1.block1 = 6;
	//Cube 2
	I1.row2 = 2;
	I1.block2 = 6;
	//Cube 3
	I1.row3 = 3;
	I1.block3 = 6;
	//Cube 4
	I1.row4 = 4;
	I1.block4 = 6;

    //Bottom, left, and right cubes
    I1.bottom_cube = 4;
    I1.left_cube = 6;
    I1.right_cube = 6;
	//Shape J
	struct Shape J0;
	//Cube 1
	J0.row1 = 1; 
	J0.block1 = 6;
	//Cube 2
	J0.row2 = 2;
	J0.block2 = 6;
	//Cube 3
	J0.row3 = 2;
	J0.block3 = 5;
	//Cube 4
	J0.row4 = 2;
	J0.block4 = 4;

    //Bottom, left, and right cubes
    J0.bottom_cube = 2;
    J0.left_cube = 6;
    J0.right_cube = 4;


	struct Shape J1;
	//Cube 1
	J1.row1 = 1; 
	J1.block1 = 6;
	//Cube 2
	J1.row2 = 1;
	J1.block2 = 5;
	//Cube 3
	J1.row3 = 2;
	J1.block3 = 6;
	//Cube 4
	J1.row4 = 3;
	J1.block4 = 6;

    //Bottom, left, and right cubes
    J1.bottom_cube = 3;
    J1.left_cube = 6;
    J1.right_cube = 5;

	struct Shape J2;
	//Cube 1
	J2.row1 = 1; 
	J2.block1 = 6;
	//Cube 2
	J2.row2 = 1;
	J2.block2 = 5;
	//Cube 3
	J2.row3 = 1;
	J2.block3 = 4;
	//Cube 4
	J2.row4 = 2;
	J2.block4 = 4;

    //Bottom, left, and right cubes
    J2.bottom_cube = 2;
    J2.left_cube = 6;
    J2.right_cube = 4;

	struct Shape J3;
	//Cube 1
	J3.row1 = 1; 
	J3.block1 = 4;
	//Cube 2
	J3.row2 = 2;
	J3.block2 = 4;
	//Cube 3
	J3.row3 = 3;
	J3.block3 = 5;
	//Cube 4
	J3.row4 = 3;
	J3.block4 = 4;

     //Bottom, left, and right cubes
    J3.bottom_cube = 3;
    J3.left_cube = 5;
    J3.right_cube = 4;

	//Shape T
	struct Shape T0;
	//Cube 1
	T0.row1 = 1; 
	T0.block1 = 5;
	//Cube 2
	T0.row2 = 2;
	T0.block2 = 6;
	//Cube 3
	T0.row3 = 2;
	T0.block3 = 5;
	//Cube 4
	T0.row4 = 2;
	T0.block4 = 4;

    //Bottom, left, and right cubes
    T0.bottom_cube = 2;
    T0.left_cube = 6;
    T0.right_cube = 4;

	struct Shape T1;
	//Cube 1
	T1.row1 = 1; 
	T1.block1 = 5;
	//Cube 2
	T1.row2 = 2;
	T1.block2 = 5;
	//Cube 3
	T1.row3 = 2;
	T1.block3 = 4;
	//Cube 4
	T1.row4 = 3;
	T1.block4 = 5;

     //Bottom, left, and right cubes
    T1.bottom_cube = 3;
    T1.left_cube = 5;
    T1.right_cube = 4;

	struct Shape T2;
	//Cube 1
	T2.row1 = 1; 
	T2.block1 = 6;
	//Cube 2
	T2.row2 = 1;
	T2.block2 = 5;
	//Cube 3
	T2.row3 = 1;
	T2.block3 = 4;
	//Cube 4
	T2.row4 = 2;
	T2.block4 = 5;

    //Bottom, left, and right cubes
    T2.bottom_cube = 2;
    T2.left_cube = 6;
    T2.right_cube = 4;

	struct Shape T3;
	//Cube 1
	T3.row1 = 1; 
	T3.block1 = 5;
	//Cube 2
	T3.row2 = 2;
	T3.block2 = 6;
	//Cube 3
	T3.row3 = 2;
	T3.block3 = 5;
	//Cube 4
	T3.row4 = 3;
	T3.block4 = 5;

     //Bottom, left, and right cubes
    T3.bottom_cube = 3;
    T3.left_cube = 6;
    T3.right_cube = 5;

	struct Shape Z0;
	//Cube 1
	Z0.row1 = 1; 
	Z0.block1 = 6;
	//Cube 2
	Z0.row2 = 1;
	Z0.block2 = 5;
	//Cube 3
	Z0.row3 = 2;
	Z0.block3 = 5;
	//Cube 4
	Z0.row4 = 2;
	Z0.block4 = 4;

     //Bottom, left, and right cubes
    Z0.bottom_cube = 2;
    Z0.left_cube = 6;
    Z0.right_cube = 4;

	struct Shape Z1;
	//Cube 1
	Z1.row1 = 1; 
	Z1.block1 = 4;
	//Cube 2
	Z1.row2 = 2;
	Z1.block2 = 5;
	//Cube 3
	Z1.row3 = 2;
	Z1.block3 = 4;
	//Cube 4
	Z1.row4 = 3;
	Z1.block4 = 5;
    
    //Bottom, left, and right cubes
    Z1.bottom_cube = 3;
    Z1.left_cube = 5;
    Z1.right_cube = 4;

	//Shape S
	struct Shape S0;
	//Cube 1
	S0.row1 = 1; 
	S0.block1 = 5;
	//Cube 2
	S0.row2 = 1;
	S0.block2 = 4;
	//Cube 3
	S0.row3 = 2;
	S0.block3 = 6;
	//Cube 4
	S0.row4 = 2;
	S0.block4 = 5;

     //Bottom, left, and right cubes
    S0.bottom_cube = 2;
    S0.left_cube = 6;
    S0.right_cube = 4;


	struct Shape S1;
	//Cube 1
	S1.row1 = 1; 
	S1.block1 = 5;
	//Cube 2
	S1.row2 = 2;
	S1.block2 = 5;
	//Cube 3
	S1.row3 = 2;
	S1.block3 = 4;
	//Cube 4
	S1.row4 = 3;
	S1.block4 = 4;

       //Bottom, left, and right cubes
    S0.bottom_cube = 3;
    S0.left_cube = 5;
    S0.right_cube = 4;