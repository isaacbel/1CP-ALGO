Program Recherche_mot;
Uses Crt;
//------------------------------------------------------------
Procedure RechercheMots(Ph: String; CH: Char; Var cpt, cpt2: Longint; Var Mot: String);
Var
  L, i: Longint;
Begin
  L := Length(Ph);
  Writeln('Length of the phrase: ', L);
  Writeln('-----------------------------------------------');
  Writeln('| Word             | Character | Count |');
  Writeln('-----------------------------------------------');
  i := 1;

  While i <= L Do
  Begin
    Mot := '';
    cpt := 0;

    While (i <= L) and (Ph[i] <> ' ') Do
    Begin
      If Ph[i] = CH Then
        cpt := cpt + 1;

      Mot := Mot + Ph[i];
      i := i + 1;
    End;

    If Mot <> '' Then
    Begin
      Delete(Ph, 1, i);
      L := L - i;
      i := 1;

      If cpt <> 0 Then
      Begin
        Writeln('| ', Mot:16, ' | ', CH:9, ' | ', cpt:5, ' |');
        cpt2 := cpt2 + 1;
      End;
    End
    Else
      i := i + 1;
  End;

  Writeln('-----------------------------------------------');

  If cpt2 > 0 Then
    Writeln('The number of words containing the character "', CH, '" is ', cpt2)
  Else
    Writeln('The character "', CH, '" does not exist in this phrase.');
End;

//--------------------------------------------------------------
Var
  Ph, S_chaine,Ch1 ,Mot: String;
  cpt,i,j,cpt2 : Longint;
  CH,ch2 : Char;
Begin
  Writeln('calcule de la frequence d''une sous chaine de character : ');
  Writeln('enter la frase ');
  Readln(Ph);
  Writeln('entrer le charactere : ');
  Readln(CH);
  For i:=1 To Length(Ph) Do
    Begin
      Ch1 := ch1 + Upcase(Ph[i]);
    End;
  ch2 := Upcase(CH);
  RechercheMots(Ph,CH , cpt,cpt2 ,Mot);
  Readln;
End.