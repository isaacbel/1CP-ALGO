Program Moy_tmp_Semaine ;
Uses Wincrt;
//--------------------------------------------------

Const
  Max = 50;
  Min = -10;
  MaxL = 100;
  MaxC = 100;
  jr = 7;
  H = 24;
  //----------------------------------------
Type
  Tind = 1..Max ;
  TinJ = 1..jr;
  TinH = 1..H ;
  TindL = 1..MaxL;
  TindC = 1..MaxC ;
  TABD1 = Array[Tind] Of Integer;
  TabH = Array[TinH] Of Integer ;
  TabD2 = Array[TindL,TindC] Of Integer;
  TabM = Array[TinJ] Of Real;
  ENAISS = Record
    JOUR : 1..31;
    MOIS : 1..12;
    AN : Integer;
  End;
  Result_J = Record
    DATNAISS : ENAISS;
    Tab1 : TabH ;
    Moy : Real;
    heure : 1..24 ;
  End;
  Tab_S = Array[TinJ] Of Result_J ;
  //-----------------------------------------------------------
  //------------------------------------------------------------
Procedure Ecrire1D(T:TabH );
Var
  i: Integer;
Begin
  For i :=1 To H Do
    Begin
      Write(T[i] ,'|') ;
    End;
End;

Procedure Ecrire1DM(T:TabM );
Var
  i: Integer;
Begin
  For i :=1 To jr Do
    Begin
      Write(T[i]:5:2, '|');
    End;
End;
//-------------------------------------------------
Procedure LecRand (Var T :TabH );
Var
  i : Integer;
Begin
  Randomize;
  For i:= 1 To H Do
    Begin
      T[i] := Min+ Random((Max - Min) + 1) ;
    End;
End;
//------------------------------------------------------------
Function MoyTab (T : TabH ) : Real;
Var
  i,cpt: Integer;
  A : Real;
Begin
  cpt := 0;
  For i:=1 To H Do
    Begin
      cpt := cpt + T[i] ;
    End;
  A := cpt / H ;
  MoyTab := A ;
End;
//-----------------------------------------------------------
Procedure Affichage (T : Tab_S );
Var
  i,k : Integer;
Begin
  Writeln('les temperature de chaque Heure de la journe ');
  For k:=1 To jr Do
    Begin
      With T[k] Do
        Begin
          With DATNAISS Do
            Writeln('Date du jour  : ',Jour,'/',Mois,'/',An);
          Ecrire1D(Tab1);
          Writeln('La Moyenne de temperature de chaque jour  :',k ,' est ' ,Moy:5:2);
        End;
    End;
End;
//----------------------------------------------------------------
Var
  Tab_Semaine: Tab_S;
  R : Result_J;
  TabM1 : TabM ;
  C,B,A : Integer;
  // Define the variable to hold weekly data
  i: Integer;
Begin
  Write('Jour : ');
  Readln(C);
  Write('Mois : ');
  Readln(B);
  Write('Année : ');
  Readln(A);
  For i := 1 To jr Do
    Begin
      With R Do
        Begin
          With DATNAISS Do
            Begin
              JOUR := C + i -1;
              MOIS := B;
              AN := A ;
            End;
          LecRand ( Tab1 );
          Moy := MoyTab (Tab1) ;
          TabM1[i] := Moy;
          Tab_Semaine[i] := R;
        End;
    End;
  Affichage(Tab_Semaine);
  Writeln('La moyene de la temperature dans la semaine est : ');
  Ecrire1DM(TabM1);
  // Display the data at the end
  Readln;
  Readln;
End.