Program  Decalage_Circulair;

function PUISS(x,y : longint):longint;
var F,i:longint;
BEGIN
	F:=1;
	For i:= 1 To y Do
	F:= F*x;
	PUISS:=F;
END;
//-----------------------------------------
				function NBPOS(n : longint):longint;
var i:longint;
BEGIN
	i:=0;
	While n  <> 0 Do
	begin
		i:= i+1;
		n:= n div 10;
	end;
	NBPOS:= i;
END;
//-----------------------------------------------

Function D_Circulair(N,K : LongInt):LongInt;
Var A,B,C,Num : LongInt;
Begin
   A := NBPOS(N);
	 B := N Div PUISS(10,A-K);
	 C := N Mod PUISS(10,A-K);
	 Num := C*PUISS(10,K) + B ;
	 D_Circulair := Num ;
End;
//------------------------------------------

Var N,Decalage,D : LongInt;
Begin
   WriteLn(' Enter le nombre N : ');
	 Readln(N);
	 WriteLn(' Enter le decalage  : ');
	 Readln(Decalage);

	 D := D_Circulair(N,Decalage);
	 WriteLn('Le nouveau nombre est : ',D);
	 Readln;
End.	 