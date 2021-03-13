#!/usr/bin/perl 
#use threads;
#
package Commande;

#https://www.tutorialspoint.com/perl/perl_oo_perl.htm
$repertoire_execution =  $ENV{'PERL5LIB'}; 
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

   bless $self, $class;
   return $self;
}


sub lanceThread {

#   my $thread1 = threads->new(\&boucle, 'premier');
#   my ( $self, $firstName ) = @_;
#   return $self->{_commande};
}

sub traiteCommande {
 my( $self ) = @_;
  
  my  $commande = shift;       # deux arguments attendus
  print "commande reçue ->$_[0]<-->$self->{consigne}<-\n" ;
  $posi = index( $_[0],$self->{consigne});	
  if($posi >= 0)
    {
       print "trouvé :\"$_[0]\" dans  \"$data\" , en position $posi\n";  
       #$scriptalancer = "/home/robot/lerobot/projRb/$self->{consigne}.sh";
       $scriptalancer = "$repertoire_execution/$self->{consigne}.sh";
       print "trouvé :\"$_[0]\" dans  \"$self->{consigne}\" , en position $posi\n";  
       print "trouvé :\"$_[0]\" dans  \"$self->{consigne}\" , en position $posi\n";  
       print "lance script :$scriptalancer";
      
       system($scriptalancer, "arg1");
       if ( $? == -1 )
         {
	   print "command failed: $!n";
	  }
        else
	  {
	   printf " resultat : %s", $?;
	  }                  
      }
}

1;
