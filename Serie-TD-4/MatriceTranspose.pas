Program Matrice_transpose;

Const
  Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max;
  TindL = 1..MaxL;
  TindC = 1..MaxC;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL, TindC] Of Integer;
  //-------------------------------------------

Procedure Ecrire2D( T:TABD2 ; NbL: TindL; NbC: TindC) ;
Var
  i,j : Integer;
Begin
  For i:=1 To NbL Do
    Begin
      For j:=1 To NbC Do
        Begin
          Write(T[i,j],' |');
        End;
      Writeln;
    End;
End;
//--------------------------------------
Procedure LecRandD2 (Var T :TABD2 ;Var NbL: TindL; Var NbC: TindC);
Var
  minI,maxI,i ,j: Integer;
Begin
  Writeln ('‘Donner le Nb de lignes du tableau ‘');
  Read(NbL);
  Writeln(' ‘Donner le Nb de colonnes du tableau ‘') ;
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
//------------------------------------------------------------------------------------------

Procedure Matrice_trans(T : TABD2; Nbl : TindL ; Nbc : TindC ; Var A : TABD2);
Var
  i,j : Integer;
Begin
  For i :=1 To Nbl Do
    Begin
      For j:=1 To Nbc Do
        Begin
          A[j,i] := T[i,j] ;
        End;
    End;
End;
//------------------------------------------------
Var
  T,A: TABD2;
  Nbl : TindL;
  Nbc : TindC;
Begin
  LecRandD2 (T , Nbl,Nbc);
  Ecrire2D(T,Nbl,Nbc);
  Matrice_trans(T,Nbl,Nbc,A);
  Writeln;
  Writeln('La matrice transpose est : ');
  Writeln;
  Ecrire2D(A,Nbc,Nbl);
  Readln;
End.