Program EMD_2014_2013 ;
Uses Crt;
//---------------------------------------------------
Const Max = 1000;
  MaxL = 100;
  MaxC = 100;
Type
  Tind = 1..Max ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabD2 = Array[TindL,TindC] Of Integer;
  //---------------------------------------------------

Procedure Lect2D(Var T:TABD2 ;Var NbL: TindL; Var NbC: TindC) ;
Var
  i,j : Integer;
Begin
  Writeln ('‘Donner le Nb de lignes du tableau ‘');
  Read(NbL) ;
  Writeln(' ‘Donner le Nb de colonnes du tableau ‘');
  Read (NbC);
  For i:=1 To NbL Do
    Begin
      For j:=1 To Nbc Do
        Begin
          Write('T[',i,',',j,']');
          Read(T[i,j]);
        End;
    End;
End;
//--------------------------------------

Procedure Ecrire2D( T:TABD2 ; NbL: TindL; NbC: TindC) ;
Var
  i,j : Integer;
Begin
  For i:=1 To NbL Do
    Begin
      For j:=1 To Nbc Do
        Begin
          Write(T[i,j] : 5,' |');
        End;
      Writeln;
    End;
End;
//-------------------------------------------------------

Function est_Egal_som_adj(T:TabD2 ;i :TindL; j : TindC ) : Boolean;
Var
  trouv : Boolean;
  K : Longint;
Begin
  If (i >= 2) And (j >= 2) Then
    Begin
      K := T[i,j+1] + T[i+1,j] + T[i,j-1] + T[i-1,j] ;
      If T[i,j] = K Then
        trouv := True
      Else trouv := False ;
      est_Egal_som_adj := trouv ;
    End;
End;
//-----------------------------------------------------------
Procedure add_Matrice(Var T2 : TabD2 ; e,i :TindL ; j : TindC; V : Integer );
Begin
  T2[e,1] := V;
  T2[e,2] := i ;
  T2[e,3] := j ;
End;
//--------------------------------------------------------------
//--------------------------------------------------------------
Var
  T,T2 : TabD2;
  Nbl : TindL;
  Nbc : TindC ;
  i,j,L,C,cpt,V : Integer;
  trouv : Boolean;
  Mot : String;
Begin
  Writeln('entrer la matrice : ');
  Lect2D(T,Nbl,Nbc);
  Writeln;
  Ecrire2D(T,Nbl,Nbc);
  cpt := 0 ;
  Mot := '' ;
  For i:=2 To Nbl-1 Do
    Begin
      For j:=2 To Nbc-1 Do
        Begin
          trouv := est_Egal_som_adj(T ,i ,j );
          If trouv = True Then
            Begin
              V := T[i,j] ;
              Writeln(T[i,j]);
              cpt := cpt + 1 ;
              add_Matrice( T2 , cpt,i ,j ,V );
              Mot := Mot + Char(T[i,j]);
            End;
        End;
    End;
  Writeln('-----------------------------------------------');
  Writeln('| valeur | line | clone |');
  Writeln('-----------------------------------------------');
  Ecrire2D(T2,cpt,3);
  Writeln;
  Writeln(Mot);
  Readln;
End.