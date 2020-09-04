----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.03.2018 22:19:54
-- Design Name: 
-- Module Name: entre_micro - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use std.textio.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity entre_micro is
    Port ( 
         clk_in  :in STD_LOGIC;
         reset_n : in STD_LOGIC;
         sdi_mic : in STD_LOGIC;
         sck_mic : out STD_LOGIC;
         cs_mic : out STD_LOGIC;
         audio_out : out std_logic_vector (15 downto 0);
         audio_valid : out STD_LOGIC
         );
end entre_micro;

    architecture Behavioral of entre_micro is

signal act_clk : std_logic;
signal audio_out_temp :  std_logic_vector (15 downto 0);
signal masque_pos : std_logic_vector (15 downto 0) ;
signal masque_neg : std_logic_vector (15 downto 0) ;
-- signal clk_lente :std_logic;
begin
         
--process (clk_in)
--variable cpt_rap :INTEGER :=0;   
--begin
--    if reset_n = '0' then
--            cpt_rap:=0;
--            clk_lente <='0';
--    end if;
-- if rising_edge (clk_in)
--       then
       
--   case cpt_rap is
--       when 1 =>
--            clk_lente <='0';
--       when 20 =>
--            clk_lente <='1';
--       when 40 =>
--             cpt_rap :=0;
--       when others => null;      
--   end case;
--   cpt_rap := cpt_rap + 1;
--end if;
     

--end process;   
   process (clk_in)
   variable cpt :INTEGER :=0;  
   variable cpt_test : INTEGER :=0; 
   
   begin
       
    if (reset_n = '0') then
       -- audio_out <="0000000000000000";
        audio_out_temp<="0000000000000000";
        masque_pos<="0111111111111111";-- x"7fff";--"
        masque_neg<="1000000000000000";-- x"7fff";--"
        audio_valid<='0';
        cpt:=0;
        cs_mic<='1';
        act_clk<='1';
    end if;
     if rising_edge (clk_in)
         then
         case cpt is
                when 0 =>
                     act_clk<='1'; 
                 when 1 to 4 => 
                     cs_mic<='0'; 
                     audio_valid<='0';
                     cpt_test :=cpt_test + 1;
              --  when 1 to 4 => 
              --       act_clk<='1'; 
                 when 5 to 16 => --le poids fort sert de bit de signe
                      audio_out_temp(20-cpt)<=sdi_mic;
                 when 17 =>
                      -- audio_out_temp(4)<=sdi_mic;
                        audio_out_temp(3 downto 0) <="0000";
                       cs_mic<='1';
                      
                 when 18 =>  
                   -- audio_out<=audio_out_temp;
                    act_clk<='0'; 
                    
                    if(audio_out_temp(15) = '1') --passage en nombre signé
                    then 
                        audio_out <= (audio_out_temp and masque_pos);--positif
                     else
                        audio_out <= audio_out_temp or masque_neg;--negatif
                     end if;
                     
               -- audio_out <=not (audio_out_temp);-- +'1';--complement a 1
                   -- cs_mic<='1';
                when 19 =>
                    audio_valid<='1';
                    report "audio_valid = ";
     
                when 30=>
                     audio_valid<='0';
                when others=> null;

         end case;     
         cpt:=cpt+1;
        
        if(cpt = 100) then
            cpt:=0;
        end if;   
       end if;
end process;
    
-- en mode concurrent
sck_mic<=clk_in and act_clk;

end Behavioral;
