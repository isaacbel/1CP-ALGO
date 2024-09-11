
Program S3Exo32Oiselier;
Uses crt;
Var
  i, j, t, s, N, jr: Longint;
  //-----------------------------

Function PUISS(X,e:Longint): Longint;
Var
  i, ps: Longint;
Begin
  ps := 1;
  For i:=1 To e Do
    ps := ps*X;
  PUISS := ps
End;
//Fin Fonction Puissance (X puissance e)
//-----------------------------

Function NBPOS(N: Longint): Integer;
Var
  Np: Integer;
Begin
  Np := 0;
  While N <> 0 Do
    Begin
      N := N Div 10;
      Np := Np+1;
    End;
  NBPOS := Np;
End;
//Fin Fonction nombre de positions d''un nombre entier
//-----------------------------

Function ExtrCh(B,p:Longint): Longint;
// ----------------------------------------------------------------------
// Donne le chiffre se trouvant a la position p (gauche,Droite) de B
// retourne 0 en cas d'erreur
// ----------------------------------------------------------------------
Begin
  If p <= NBPOS(B) Then
    ExtrCh := B Div PUISS(10,NBPOS(B)-p) Mod 10
  Else ExtrCh := 0;
End;
//Fin Fonction Extrch
//-----------------------------

Function ExtCP(N,c,p: Longint): Longint;
{extrait c chiffres de N à partir de la position p}
Var
  x: Longint;
Begin
  x := (N Div (PUISS (10,p-1)));
  x := (x-((x Div (PUISS (10,c))*(PUISS(10,c)))));
  extCP := x;
End;
//---------------------------

Function Concat(a,b: Longint): Longint;
{ ex: a=12 b=53 concat(a,b)=1253}
Begin
  Concat := ((a*(PUISS (10,NBPOS(b))))+b);
End;
//---------------------------

Function SuppCH(N, ch: Longint): Longint;
{Donne le nombre N sans le chiffre ch}
Var
  res, i ,p: Longint;
Begin
  res := 0;
  For i:=1 To NBPOS(N) Do
    Begin
      p := ExtCP(N,1,i);
      If p<>ch Then res := Concat(p,res);
    End;
  SuppCH := res;
End;
//---------------------------
Begin
  //Principal
  Clrscr;
  Repeat
    Writeln;
    Write('Entrer les nombres des oiseaux dans les cases au 1er jour: ');
    Readln(N);{*nb des oiseaux dans les cases 1er jr*}
    Writeln;
    Write(' Entrer le nieme jour : ');
    Readln(jr); {*le nieme jr*}
    Writeln;
    For i:=2 To jr Do
      Begin
        s := 0;
        For j:=1 To NbPos(N) Do
          Begin
            If ExtrCh(N,j) <>0 Then
              s := PUISS (10, NBPOS(N) - j) + s;
          End;
        N := (N-s)*10 + NBPOS(N);
        N := SuppCh(N,0);
        //on supprime les 0 du nombre N
      End;
    Writeln('le nombre des volieres occupees le ',Jr,' ieme jours est : ',NBPOS(N));
    Writeln('les oiseaux sont repartis dans les ', NBPOS(N),' volieres comme suit :');
    Write (' ---> ');
    For t:=1 To NBPOS(N) Do
      Write(ExtrCh(N,t),' , ');
  Until Readkey = Chr(27);
  Writeln;
  Readln;
End.
//Final
