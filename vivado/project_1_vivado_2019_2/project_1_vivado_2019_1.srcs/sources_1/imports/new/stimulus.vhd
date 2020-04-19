----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10.04.2018 22:53:16
-- Design Name: 
-- Module Name: stimulus - Behavioral
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

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use std.textio.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity stimulus is
   -- Port ( 
    --audio_micro_out : out STD_LOGIC;
    --clk_micro_in : in STD_LOGIC
       
  --   cs_mic_0_sim : out STD_LOGIC;
  --   gain_ampli_0_sim : out STD_LOGIC;
  --   sck_mic_0_sim :  out STD_LOGIC;
  --   sdi_mic_0_sim :  in STD_LOGIC;
  --   shd_ampli_0_sim : out  STD_LOGIC;
  --   sortie_pwm_0_sim : out STD_LOGIC
  --   );
end stimulus;

architecture Behavioral of stimulus is
    
    signal clk: std_logic := '0';
    
    signal DDR_addr_sim : std_logic_vector ( 14 downto 0 );
    signal DDR_ba_sim :  STD_LOGIC_VECTOR ( 2 downto 0 );
    signal DDR_cas_n_sim :  STD_LOGIC;
    signal DDR_ck_n_sim :  STD_LOGIC;
    signal DDR_ck_p_sim :  STD_LOGIC;
    signal DDR_cke_sim :  STD_LOGIC;
    signal DDR_cs_n_sim :  STD_LOGIC;
    signal DDR_dm_sim :  STD_LOGIC_VECTOR ( 3 downto 0 );
    signal DDR_dq_sim :  STD_LOGIC_VECTOR ( 31 downto 0 );
    signal DDR_dqs_n_sim :  STD_LOGIC_VECTOR ( 3 downto 0 );
    signal DDR_dqs_p_sim :  STD_LOGIC_VECTOR ( 3 downto 0 );
    signal DDR_odt_sim :  STD_LOGIC;
    signal DDR_ras_n_sim :  STD_LOGIC;
    signal DDR_reset_n_sim :  STD_LOGIC;
    signal DDR_we_n_sim :  STD_LOGIC;
    signal FIXED_IO_ddr_vrn_sim :  STD_LOGIC;
    signal FIXED_IO_ddr_vrp_sim :  STD_LOGIC;
    signal FIXED_IO_mio_sim :  STD_LOGIC_VECTOR ( 53 downto 0 );
    signal FIXED_IO_ps_clk_sim :  STD_LOGIC;
    signal FIXED_IO_ps_porb_sim :  STD_LOGIC;
    signal FIXED_IO_ps_srstb_sim :  STD_LOGIC;
    signal LedA_sim :  STD_LOGIC;
    signal LedB_sim :  STD_LOGIC;
    signal LedC_sim :  STD_LOGIC;
    signal LedD_sim :  STD_LOGIC;
    signal cs_mic_0_sim : STD_LOGIC;
    signal entree_bouton_1_sim: STD_LOGIC;
    signal gain_ampli_0_sim :  STD_LOGIC;
    signal sck_mic_0_sim :  STD_LOGIC;
    signal sdi_mic_0_sim :  STD_LOGIC;
    signal shd_ampli_0_sim :  STD_LOGIC;
    signal sortie_pwm_0_sim :  STD_LOGIC;
    signal gpio_io_i_0_sim:  STD_LOGIC_VECTOR ( 3 downto 0 );
    signal cs_avant : STD_LOGIC;
    signal valeur_audio :  STD_LOGIC_VECTOR( 15 downto 0 ) := "0000000000000000";
begin

-- I/O Connections assignments
design_1_wrapper_inst : entity work.design_1_wrapper port map( 
        DDR_addr=>DDR_addr_sim,
        DDR_ba=>DDR_ba_sim,
        DDR_cas_n=>DDR_cas_n_sim,
        DDR_ck_n=>DDR_ck_n_sim ,
        DDR_ck_p=>DDR_ck_p_sim ,
        DDR_cke=>DDR_cke_sim ,
        DDR_cs_n=>DDR_cs_n_sim ,
        DDR_dm=>DDR_dm_sim ,
        DDR_dq=>DDR_dq_sim ,
        DDR_dqs_n=>DDR_dqs_n_sim ,
        DDR_dqs_p=>DDR_dqs_p_sim ,
        DDR_odt=> DDR_odt_sim,
        DDR_ras_n=>DDR_ras_n_sim ,
        DDR_reset_n=>DDR_reset_n_sim,
        DDR_we_n=>DDR_we_n_sim ,
        FIXED_IO_ddr_vrn=>FIXED_IO_ddr_vrn_sim ,
        FIXED_IO_ddr_vrp=> FIXED_IO_ddr_vrp_sim,
        FIXED_IO_mio=> FIXED_IO_mio_sim,
        FIXED_IO_ps_clk=> FIXED_IO_ps_clk_sim,
        FIXED_IO_ps_porb=>FIXED_IO_ps_porb_sim ,
        FIXED_IO_ps_srstb=>FIXED_IO_ps_srstb_sim ,
        LedA=> LedA_sim ,
        LedB=> LedB_sim,
        LedC=>LedC_sim ,
        LedD=>LedD_sim ,
        cs_mic_0=> cs_mic_0_sim,
        gain_ampli_0=> gain_ampli_0_sim,
        sck_mic_0=> sck_mic_0_sim,
        sdi_mic_0=> sdi_mic_0_sim,
        shd_ampli_0=> shd_ampli_0_sim,
        sortie_pwm_0=> sortie_pwm_0_sim,
        gpio_io_i_0=>gpio_io_i_0_sim
   );
  
    process(sck_mic_0_sim,cs_mic_0_sim) --modelise le micro 
    
    variable cpt_bit :INTEGER :=0;  
    file read_file : text;
    variable slv_v  :INTEGER :=0;  
    variable line_num : line;
    file write_file : text;
    variable nb_ech_calc :INTEGER :=0; 
    variable nb_ech_envoyu :INTEGER :=0;
    variable qq :INTEGER :=1; 
    variable val_audio_interger :INTEGER  :=0;
    variable line_content : string(1 to 16);
    variable v_data_read            : integer;
    variable j :INTEGER :=0;
    variable i :INTEGER :=0;
    variable ouv : INTEGER:=0;
    variable ouvert : integer:=0;
    variable cpt :INTEGER :=0;  
    begin  
        if ouvert = 0 then 
            file_open(write_file, "/home/nicolas/target.txt", write_mode);
            file_open(read_file, "/home/nicolas/vivado/source.txt", read_mode);
            ouvert:=1;
        end if;
      --  le micro envoie 16 bits sur font monté d'horloge avec 
    --                --  les 12 bits significatifs poids faible à la fin
      --  file_open(write_file, "/home/nicolas/target.txt", write_mode);
    
      
--        if falling_edge (sck_mic_0_sim)
--            then
--            if(ouv = 0)
--            then
--                file_open(read_file, "/home/nicolas/vivado/source.txt", read_mode);
                
--                ouv :=1;
--                entree_bouton_1_sim<='0';
--                 j:=0;
               
--            end if;
--            if (cs_mic_0_sim='1')
--                then
--                j:=0;
--                 sdi_mic_0_sim <='0';
--                end if;
--             if (cs_mic_0_sim='0')
--                then

--                if(j = 0)     then
--                     if not endfile(read_file) then
--                        readline(read_file, line_num);
--                        READ(line_num,line_content);
--                        report "1simulateur audio = " & line_content;
--                    end if;
--                end if;
--                if(j <3)     then
--                     sdi_mic_0_sim<='0';
--                end if;
                 
--                if ((j >2)and(j <= 14)) then 
--                        if(line_content(j-2) = '0') then
--                            sdi_mic_0_sim<='0';
                           
--                        else
--                             sdi_mic_0_sim <='1';
                             
--                        end if;
                       
--                 end if;
--                  report  "[" & integer'image(j) & "]" & std_logic'image(sdi_mic_0_sim);
--                j:=j+1;
--         --  end if;
--         end if; --(cs_mic_0_sim='0')
--      end if; --falling_edge 
    if (cs_mic_0_sim='0')
    then
    if falling_edge (sck_mic_0_sim)
         then
         case cpt is
            when 0  to 15 => --les 4 premiers bits ne sont pas lus
                 if(cpt = 0) then 
                    if endfile(read_file) then
                        file_close(read_file);-- rembobinnage
                        file_open(read_file, "/home/nicolas/vivado/source.txt", read_mode);
                      end if;
                     
                     
                   -- if not endfile(read_file) then
                        readline(read_file, line_num);
                        READ(line_num,line_content);
                       report "1simulateur audio = " & line_content;
                    
                      
                end if;                 

            -- when 1 to 3 => 
               
          --   when 1 to 16 =>
                 if(line_content(cpt+1) = '0') then -- on lit le fichier micro
                    sdi_mic_0_sim<='0';
                   --  report "0";
                else
                     sdi_mic_0_sim <='1';
                   --  report "1";
                end if;
             
            when others=> null;

         end case;     
         cpt:=cpt+1;
        
          --  if(cpt = 37) then
            --    cpt:=0;
           -- end if;   
       end if;
           else          
           cpt :=0;   
       end if ;--if (cs_mic_0_sim='0')
    end process;     
end Behavioral;
