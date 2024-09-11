Program Produit_Matrice ;
Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;
  //--------------------------------------------
  //--------------------------------------------

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
//-------------------------------------------------------

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
//-----------------------------------------------------
Procedure Produit_matrc(T,A : TABD2 ; Nbl1,Nbl2 : TindL; Nbc1,Nbc2 : TindC; Var P : TabD2 );
Var
  i,j,k , S : Longint;
Begin
  For i:= 1 To Nbl1 Do
    Begin
      For K:=1 To Nbc2 Do
        Begin
          S := 0;
          For j := 1 To Nbc1 Do
            Begin
              S := S + T[i,j] * A[j,k] ;
            End;
          P[i,k] := S ;
        End;
    End;
End;
//--------------------------------------------------------------------
Var
  T,A,P : TabD2;
  Nbl1,Nbl2 : TindL;
  Nbc1,Nbc2 : TindC;
Begin
  Writeln(' Le produit de deux Matrice ');
  LecRandD2(T,Nbl1,Nbc1);
  Ecrire2D(T,Nbl1,Nbc1);
  Writeln;
  LecRandD2(A,Nbl2,Nbc2);
  Ecrire2D(A,Nbl2,Nbc2);
  If Nbc1=Nbl2 Then
    Begin
      Produit_matrc(T,A , Nbl1,Nbl2 , Nbc1,Nbc2 , P );
      Writeln('Le Produit est : ');
      Writeln;
      Ecrire2D(P,Nbl1,Nbc2);
    End
  Else
    Writeln(

         'Le nombre de colone de la Matrice T n''est pas egale a le nombre de line de la matrice A '
    );
  Readln;
End.