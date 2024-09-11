Program Point_Salle ;
//----------------------------------------
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
  //----------------------------------------------------
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
      For j:=1 To NbL Do
        Begin
          Write('T[',i,',',j,'] = ');
          Read(T[i,j]);
        End;
    End;
End;
//------------------------------------------------------
Procedure Ecrire2D( T:TABD2 ; NbL: TindL; NbC: TindC) ;
Var
  i,j : Integer;
Begin
  For i:=1 To NbL Do
    Begin
      For j:=1 To NbL Do
        Begin
          Write(T[i,j],' |');
        End;
      Writeln;
    End;
End;
//------------------------------------------------------
Procedure maxTab1D(T :TABD2 ; i: TindL;Nbc :TindC;Var K : Integer;Var maxT : Longint);
Var
  j: Integer;
Begin
  maxT := T[i,1] ;
  K := 1;
  For j:=2 To Nbc Do
    Begin
      If maxT < T[i,j] Then
        Begin
          maxT := T[i,j];
          K := j;
        End;
    End;
End;
//-----------------------------------------------------------

Procedure minTab1D(T :TABD2 ; Nbl: TindL;j :TindC ; Var K : Integer; Var minT : Longint );
Var
  i : Integer;
Begin
  minT := T[1,j] ;
  K := 1;
  For i:=2 To Nbl Do
    Begin
      If minT > T[i,j] Then
        Begin
          minT := T[i,j];
          K := i;
        End;
    End;
End;
//-------------------------------------------------------------
Procedure Point_de_Selle(T : TABD2 ;NbL : TindL ; Nbc : Tind ; Var P : Longint);
Var
  i, j, K, cpt,maxt,mint,L: Integer;
  // Assuming these variables are needed
  Bool: Boolean;
Begin
  cpt := 0;
  For i:=1 To Nbl Do
    Begin
      maxTab1D(T , i,Nbc , K , maxt );
      j := k;
      minTab1D(T , Nbl,j , L , mint );
      If mint=maxt Then
        Begin
          P := mint;
          Writeln('le point de salle est : ' ,P );
          Writeln;
          cpt := cpt +1 ;
        End;
    End;
  If cpt = 0 Then
    Writeln('il y a aucun point de salle ');
End;
//------------------------------------------------------
Var
  T: TABD2;
  Nbc : TindC;
  Nbl : TindL;
  P : Longint;
Begin
  Writeln(' Le point de selle ');
  Lect2D(T,Nbl,Nbc);
  Writeln;
  Ecrire2D(T,Nbl,Nbc);
  Writeln;
  Point_de_Selle(T , NbL, Nbc , P );
  Readln;
  Readln;
End.
