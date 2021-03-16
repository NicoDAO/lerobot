#!/usr/bin/perl 
#use threads;
#
package Commande;

#https://www.tutorialspoint.com/perl/perl_oo_perl.htm
$repertoire_execution =  $ENV{'PERL5LIB'}; 

my $resultat = "rien";
sub retour{
 print "résultat";
  return "retour =  $resultat";
}

sub boucle {
#    my $thread = shift;
    my $toto = 50;
    #while($toto--) { print "dans le thread $thread\n" }
#    threads->yield;
    $toto = 50;
    while($toto--) 
    	{
    	    print "dans le thread $thread\n";
    	    sleep(1);
    	}
   
    }
sub new {
   my ($class) = shift;    
   my $self = {
        consigne => shift,       
    };   
   print "Fonction implémentée =  $self->{consigne}\n";
	 $resultat = "rien";
   bless $self, $class;
   return $self;
}


sub lanceThread {

}

sub traiteCommande {
 my( $self ) = @_;
  
   $retour = "  ";
  my  $commande = shift;       # deux arguments attendus
  print "commande reçue ->$_[0]<-->$self->{consigne}<-\n" ;
  $posi = index( $_[0],$self->{consigne});
  #$posi = index( $self->{consigne},$_[0]);
  print "position $posi";
  if($posi >= 0)
    {
       print "trouvé :\"$_[0]\" dans  \"$data\" , en position $posi\n";  
       #$scriptalancer = "/home/robot/lerobot/projRb/$self->{consigne}.sh";
       $scriptalancer = "$repertoire_execution/$self->{consigne}.sh";
       print "trouvé :\"$_[0]\" dans  \"$self->{consigne}\" , en position $posi\n";  
       print "trouvé :\"$_[0]\" dans  \"$self->{consigne}\" , en position $posi\n";  
       print "lance script :$scriptalancer";
      
      
       system($scriptalancer, "arg1");
       
       $le_retour=$_[0] + "recu OK";
       $resultat = "oki";
       $retour = "ok";
       if ( $? == -1 )
         {
	   print "command failed: $!n";
	  }
        else
	  {
	   printf " resultat : %s", $?;
	  }   
	                
      }else{
        $resultat = "~~~~~~~~";
        $retour="NOK"
         }	
 return $retour
}

1;
