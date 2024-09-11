Procedure Ecrire2D(T:Tab2D; nL:TindL;nC:TindC) ;
//Affichage de tableaux 2D
var i, j :integer;
begin
	for i:= 1 to nL do
	Begin
    for j:=1 to nC do
				  write(T[i,j]:8,'|');
		writeln;
	End;
end;  //fin Ecrire2D 