#!/usr/bin/python
import os
import shutil
import sys


def Detect_Project(name_path):

    if "cn12_development" in name_path:
        Status = 1 #C15 project
        file_algo = "rb_alg_AlgoParameters_RomCfg.c" #C15 project
        file_variant = "rb_swvc_SoftwareVersion_Cfg.c" #C15 project
        algo_path = name_path + "\\" + "rb_cfg_Config\\rb_cfgi_ConfigImplementation\\rb_cfic_AlgoCalibrationParameters" + "\\"
        variant_path = name_path + "\\" + "rb_cfg_Config\\rb_cfgi_ConfigImplementation\\rb_cfis_ConfigImplSystemSW" + "\\"

    else :
        Status = 0 #C13 project
        file_algo = "rb_alg_AlgoParameters_EeCfg.c" #C13 project
        file_variant = "rb_swvc_SoftwareVersion_EeCfg.c" #C13 project
        algo_path = name_path + "\\" + "rb_cfg_Config\\rb_cfge_ConfigEe\\rb_cfep_ConfigEeAppl" + "\\"
        variant_path = name_path + "\\" + "rb_cfg_Config\\rb_cfge_ConfigEe\\rb_cfes_ConfigEeSystemSW" + "\\"

    return file_algo,file_variant,algo_path,variant_path,Status

def Algo_ID_Parameter(name_path,file_algo,algo_path):
    #Switch state
    Status = False

    # state = 1 => Algo_ProjectHB
    # state = 2 => Algo_ProjectLB
    # state = 3 => Algo_ParaID
    state = 0

    os.chdir(algo_path)

    f = open(file_algo,"r")
    for line in f:
        if Status == True:
            Status = False
            if state == 1 :
                Algo_ProjectHB = line
            elif state == 2 :
                Algo_ProjectLB = line
            elif state == 3 :
                Algo_ParaID = line 
            else :
                pass

        if "rb_acc_AidaParametersAlgoIds_cst.ProjIdHB_u8" in line :
            Status = True
            state = 1
        if "rb_acc_AidaParametersAlgoIds_cst.ProjIdLB_u8" in line :
            Status = True
            state = 2
        if "rb_acc_AidaParametersAlgoIds_cst.ParaId_u8" in line:
            Status = True
            state = 3
        #print(line)
    f.close()

    Algo_Para = [Algo_ProjectHB,Algo_ProjectLB,Algo_ParaID]
    Algo_Para_temp = ["","",""]
    Algo_Para_final = ["","",""]
    for i in range(0,3,1):
        Algo_Para[i] = Algo_Para[i].lstrip("  ")
        Algo_Para_temp[i] = Algo_Para[i].split(",")
        Algo_Para_final[i] = hex(int(Algo_Para_temp[i][0]))

    for i  in range(0,3,1):
        if len(Algo_Para_final[i]) == 3 :
            Algo_Para_final[i] = Algo_Para_final[i].lstrip("0x")
            Algo_Para_final[i] = "0" + Algo_Para_final[i]
        else :
            Algo_Para_final[i] = Algo_Para_final[i].lstrip("0x")
            Algo_Para_final[i] = Algo_Para_final[i].upper()

    Algo_ID = Algo_Para_final[0] + Algo_Para_final[1] + Algo_Para_final[2]

    return Algo_ID


def Variant_ID_Parameter(name_path,file_variant,variant_path,Status):

    # state = 1 => Algo_ProjectHB
    # state = 2 => Algo_ProjectLB
    # state = 3 => Algo_ParaID
    state = 0

    count = 0

    os.chdir(variant_path)

    f = open(file_variant,"r")
    for line in f:

        if "#define RB_swv_VariantNumber_cu16" in line :
            count = count + 1
            if count == 2:
                VariantNumber = line
                state = 1

        if "#define RB_swv_VariantVersion_cu16" in line :
            count = count + 1
            if count == 4:
                VariantVersion = line
                state = 2
        
        #print(line)
    f.close()

    VariantID_temp = ["VariantNumber_temp","VariantVersion_temp"]
    VariantID_final = ["VariantNumber_final","VariantVersion_final"]
    VariantID_correct_final = ["VariantNumber_correct_final","VariantVersion_correct_final"]


    if Status==0:
        VariantNumber_temp  = VariantNumber.split("0x")
        VariantNumber_final  = VariantNumber_temp[1].split(" ")
        VariantNumber_correct_final = str(VariantNumber_final[0][0:4])


        VariantVersion_temp  = VariantVersion.split("0x")
        VariantVersion_final  = VariantVersion_temp[1].split(" ")
        VariantVersion_correct_final = str(VariantVersion_final[0][0:4])

    else:

        VariantNumber_temp  = VariantNumber.split(")")
        VariantNumber_final  = VariantNumber_temp[0].split("(")
        VariantNumber_final_correct = hex(int(VariantNumber_final[1])).split("0x")

        VariantVersion_temp  = VariantVersion.split(")")
        VariantVersion_final  = VariantVersion_temp[0].split("(")
        VariantVersion_final_correct = hex(int(VariantVersion_final[1])).split("0x")


        if len(VariantVersion_final_correct[1]) == 1 :
            VariantVersion_correct_final = "000" + VariantVersion_final_correct[1]
        elif len(VariantVersion_final_correct[1]) == 2 :
            VariantVersion_correct_final = "00" + VariantVersion_final_correct[1]
        elif len(VariantVersion_final_correct[1]) == 3 :
            VariantVersion_correct_final = "0" + VariantVersion_final_correct[1]
        elif len(VariantVersion_final_correct[1]) == 4 :
            VariantVersion_correct_final = VariantVersion_final_correct[1]
        else:
            pass

        if len(VariantNumber_final_correct[1]) == 1 :
            VariantNumber_correct_final = "000" + VariantNumber_final_correct[1]
        elif len(VariantNumber_final_correct[1]) == 2 :
            VariantNumber_correct_final = "00" + VariantNumber_final_correct[1]
        elif len(VariantNumber_final_correct[1]) == 3 :
            VariantNumber_correct_final = "0" + VariantNumber_final_correct[1]
        elif len(VariantNumber_final_correct[1]) == 4 :
            VariantNumber_correct_final = VariantNumber_final_correct[1]
        else :
            pass
    
    Variant_ID = VariantNumber_correct_final + "_" + VariantVersion_correct_final
    print(Variant_ID)
    return Variant_ID


def Label_software(name_path,Algo_ID,Variant_ID):

    count = 0
    string_2 = "a"
    string_5 = "b"

    #----------------------------- Folder name ---------------------------
    string = name_path + "\\" + "results" + "\\"
    os.chdir(string)

    string_1 = os.listdir()

    for i in string_1 :
        if ".hex" in i:
            count = count + 1
            if count == 1:
                string_2 = i

    string_3 = string_2.split('.hex')
    print(string_3)
    #print(string_2[0])
    string_4 = string_3[0].split('_')
    string_5 = string_4[3] + '_' + string_4[1] + '_' + string_4[2] + '_' + Variant_ID + '_' + Algo_ID
    #----------------------------------------------------------------------
    return string_5,string_4


def Create_folder(fol_create_name,name_path):

    #------------------------------ Create Folder ---------------------------
    sandboxes_path = name_path
    #print(string[0])
    # sandboxes_path[0] = link sandboxes
    # sandboxes_path[1] = File merge

    os.chdir(sandboxes_path)
    #print(os.getcwd())

    if os.path.exists(fol_create_name):
        os.rmdir(fol_create_name)
        os.mkdir(fol_create_name)
    else :
        os.mkdir(fol_create_name)
    #print(os.listdir())
    
    os.chdir(fol_create_name)
    #print(os.getcwd())

    # package of plant
    os.mkdir(fol_create_name)
    #print(os.getcwd())

    #package of verify
    fol_create_plant = fol_create_name
    fol_create_verify = fol_create_name + "_" + "VERIFY"
    os.mkdir(fol_create_verify)
    #print(os.getcwd())

    #return to the sandbox path
    os.chdir(sandboxes_path)
    #------------------------------------------------------------------------

    return sandboxes_path,fol_create_plant,fol_create_verify

def Plant_folder(Variant_ID,Algo_ID,name_merge_plant,fol_create_plant,sandboxes_path):

    #compo_file_temp = name_merge_plant.rstrip('_merged.hex')
    #compo_file = compo_file_temp.split('_')
    compo_file_final = name_merge_plant[0] + '_' + name_merge_plant[1] + '_' + name_merge_plant[2] + '_' + name_merge_plant[3] + '_' + name_merge_plant[4]

    #------------------------------ Create Folder Container ---------------------------

    src = ["src_sad","src_cns","src_flt","src_flt"]
    dst = ["dst_sad","dst_cns","dst_flt","dst_nvm"]
    name_last = [".sad",".cns",".flt",".nvm"]
    
    #Maintain the file name in plant folder
    dst_temp = sandboxes_path + "\\" + fol_create_plant + "\\" + fol_create_plant + "\\" + compo_file_final
    src_temp  = sandboxes_path + "\\" + "results" + "\\" + compo_file_final
    
    print(dst_temp, src_temp)
    for i in range(0,4,1):
        src[i] = src_temp + name_last[i]
        dst[i] = dst_temp + name_last[i]
        #Copy file 
        shutil.copyfile(src[i],dst[i])


    old_name_temp = Variant_ID + "_" + Algo_ID
    new_name_sad_temp = dst[0].split("Cat")
    new_name = ['new_name_sad','new_name_cns','new_name_flt','new_name_nvm']

    for i in range(0,4,1):
        new_name[i] = new_name_sad_temp[0] + old_name_temp + name_last[i]
        os.rename(dst[i],new_name[i])


    #-------------------------------------- Take Merge file --------------------------
    src_hex = sandboxes_path + "\\" +  "merge.hex"
    dst_hex = sandboxes_path + "\\" + fol_create_plant + "\\" + fol_create_plant + "\\" + "merge.hex"
    #print (dst_hex)
    shutil.copyfile(src_hex,dst_hex)
    
    new_name_hex = new_name_sad_temp[0] + old_name_temp + ".hex"
    os.rename(dst_hex,new_name_hex)
    #---------------------------------------------------------------------------------


def Verify_folder(name_merge_plant,fol_create_plant,fol_create_verify,sandboxes_path):

    count = 0

    # compo_file_temp = name_merge_plant.rstrip('_merged.hex')
    # compo_file = compo_file_temp.split('_')
    compo_file_final = name_merge_plant[0] + '_' + name_merge_plant[1] + '_' + name_merge_plant[2] + '_' + name_merge_plant[3] + '_' + name_merge_plant[4]

    #Maintain the file name in plant folder
    src = sandboxes_path + "\\" + "results_cat5" + "\\" 
    src_nvm = src + compo_file_final + ".nvm"
    src_map = src + compo_file_final + ".map"

    dst = sandboxes_path + "\\" + fol_create_plant + "\\" + fol_create_verify + "\\"
    dst_nvm = dst + compo_file_final + ".nvm"
    dst_map = dst + compo_file_final + ".map"

    #Copy file 
    shutil.copyfile(src_nvm,dst_nvm)
    shutil.copyfile(src_map,dst_map)


    #-------------------------------------- Take Merge file --------------------------
    os.chdir(src)
    array = os.listdir()

    for i in array:
        count = count + 1
        if count == 13 :
            merge_release = i

    src_hex = sandboxes_path + "\\" + "results_cat5" + "\\" + merge_release
    dst_hex = sandboxes_path + "\\" + fol_create_plant + "\\" + fol_create_verify + "\\" + merge_release

    #Copy file 
    shutil.copyfile(src_hex,dst_hex)

    new_name_hex = dst + compo_file_final + ".hex"
    os.rename(dst_hex,new_name_hex)
    #----------------------------------------------------------------------------------


def main():

    #----------------------------- Data and Constant ---------------------------
    #name_path = input("Please choose the sandboxes :\n")
    name_path = str(sys.argv[1])
    #----------------------------------------------------------------------

    file_algo,file_variant,algo_path,variant_path,Status = Detect_Project(name_path)
    Algo_ID = Algo_ID_Parameter(name_path,file_algo,algo_path)
    Variant_ID = Variant_ID_Parameter(name_path,file_variant,variant_path,Status)

    fol_create_name,name_merge_plant = Label_software(name_path,Algo_ID,Variant_ID)
    sandboxes_path,fol_create_plant,fol_create_verify = Create_folder(fol_create_name,name_path)

    Plant_folder(Variant_ID,Algo_ID,name_merge_plant,fol_create_plant,sandboxes_path)
    Verify_folder(name_merge_plant,fol_create_plant,fol_create_verify,sandboxes_path)


    
if __name__== "__main__":
    main()