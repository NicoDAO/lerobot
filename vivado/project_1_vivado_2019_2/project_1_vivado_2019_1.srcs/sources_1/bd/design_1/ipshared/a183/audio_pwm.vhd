--https://eewiki.net/pages/viewpage.action?pageId=10125324
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
  
entity interfaceCodec is
	generic (
    -- Users to add parameters here

    -- User parameters ends
    -- Do not modify the parameters beyond this line

    -- Width of S_AXI data bus
    C_S_AXI_DATA_WIDTH    : integer    := 32;
    -- Width of S_AXI address bus
    C_S_AXI_ADDR_WIDTH    : integer    := 4;
    NOMBRE_DE_PAS_PWM : integer :=1024 --4096
);
Port ( 
    reset_n    :  in STD_LOGIC;                    --active low reset
    gain_ampli :out std_logic;
    clk_filtre  : in  STD_LOGIC;
    sortie_pwm : out std_logic ;
    shd_ampli : out std_logic ;
    audio1 : in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
    entree_audio1 : in std_logic_vector(23 downto 0);
    entree_audio1_prete :in std_logic     
     );
end interfaceCodec;
 
architecture arch_imp of interfaceCodec	 is
 
                                                        
signal state_machine1 : STD_LOGIC_VECTOR(1 downto 0);
signal state_machine1_return : STD_LOGIC_VECTOR(1 downto 0);                                                                   

signal entree_audio1_C : STD_LOGIC_VECTOR(23 downto 0);


signal clk1 : STD_LOGIC; 
signal clk2 : STD_LOGIC; 

begin

process (clk_filtre,state_machine1_return,reset_n,audio1)
variable  cpt_audio  : INTEGER;
variable valeur_sortie :  integer;
variable valeur_audio_sortie : integer;
variable audio_depuis_axi : integer;
begin
    if(reset_n ='0') then
        state_machine1 <="00";
        cpt_audio :=0;
        valeur_sortie :=0;
        gain_ampli  <='0';
       shd_ampli <='0';
       audio_depuis_axi:=0;
    else
        if rising_edge(clk_filtre) then
            shd_ampli<=audio1(31);
            gain_ampli<=audio1(30);
            if( audio1(29) = '0') then
                if(valeur_sortie<  to_integer(unsigned(entree_audio1_C(11 downto 0) ) ) ) 
                    then 
                        sortie_pwm <= '0';
                    else --audio1(cpt_audio);
                        sortie_pwm<='1';
                end if;
            else
               if( audio1(29) = '1') then
                    if(valeur_sortie<  to_integer(unsigned(audio1(11 downto 0) ) ) ) 
                        then 
                            sortie_pwm <= '0';
                        else --audio1(cpt_audio);
                            sortie_pwm<='1';
                    end if;
                end if ;
            end if;
            if(valeur_sortie> NOMBRE_DE_PAS_PWM) then 
                    valeur_sortie:=0;
                else
                    valeur_sortie :=valeur_sortie+1;
            end if;

        end if;--clk
end if;--reset_n

end process;

process (entree_audio1_prete,reset_n)
begin
    if(reset_n ='0') then
        state_machine1_return <="00";
    else
        if rising_edge(entree_audio1_prete) then
                entree_audio1_C <= entree_audio1;
        end if;
    end if;

end process;

end arch_imp;

