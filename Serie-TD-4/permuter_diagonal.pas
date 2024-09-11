Program permute_diagonal ;


Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;

Procedure Ecrire2D( T:TABD2 ; NbL: TindL;  NbC: TindC) ;
Var i,j : Integer;
Begin
   For i:=1 To NbL Do
	    Begin
			  For j:=1 To Nbc do
				   Begin

							Write(T[i,j],' |');
					 End;
					 Writeln;
			End;
End;
//--------------------------------------------------
	Procedure LecRandD2 (Var T :TABD2 ;Var NbL: TindL; Var NbC: TindC);
Var
  minI,maxI,i ,j: Integer;
Begin
  	WriteLn ('‘Donner le Nb de lignes du tableau ‘');
   Read(NbL);
   WriteLn(' ‘Donner le Nb de colonnes du tableau ‘') ;
   Read (NbC);
  Writeln('Iintervale [minI, maxI]des valeurs à prendre aléatoirement');
  Writeln('---------------------------------------------------------');
  Write('Donner la borne inférieure : ');
  Readln(minI);
  Write('Donner a borne supérieure : ');
  Readln(maxI);
  Randomize;
  For i:= 1 To NbL Do
    Begin
		  For j:=1 To NbC Do
			Begin
        T[i,j] := minI + Random((maxI - minI) + 1) ;
			End;
    End;
End;
//------------------------------------------------------------------
//--------------------------------------------------
Procedure PERMUT (Var A, B: Longint);
//permute les contenus de A et B
Var Tmp: Longint;
Begin
  Tmp := A;
  A := B;
  B := Tmp;
End; //fin Permut

Procedure per_dia(Var T : TabD2 ; Nbl:TindL ;Nbc:TindC);
Var  i,j : Integer;
Begin
  j:= Nbc;
  For i:=1 To Nbl Do
	  Begin
		   PERMUT (T[i,i], T[i,j]);
			 j:=j-1;
		End;	 
		  
End;

Var  T :TabD2;
     Nbl : TindL;
		 Nbc : TindC;
Begin
	LecRandD2 (T,NbL,NbC);
	Ecrire2D(T, NbL,  NbC) ;
	WriteLn;
	per_dia(T, NbL,  NbC);
	Ecrire2D(T, NbL,  NbC) ;
	Readln;
End.