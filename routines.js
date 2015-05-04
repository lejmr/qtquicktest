function filter_cmd() {
    /*
      Function composes filter command based on app options
    */

    var filter_cmd = "./filter"
    var filter_opts = " -i "+input_file_field.text+" -o "+output_dir_field.text+" -s "+size_field.text

    switch(analysis_type.currentIndex){

        case 0:
            filter_opts += " -p ip"
            break;
        case 1:
            filter_opts += " -p sip -p ip"
            break;
        case 2:
            filter_opts += " -p tcp -p ip"
            break;
        case 3:
            filter_opts += " -p dns"
            break;

        default:
            log_output.text = "Unknown option"
            return false
    }

    return filter_cmd + filter_opts
}


function worker_cmd() {
    /*
      Function composes worker command based on app options
    */

    var worker_cmd = "./savesip"
    var worker_opts = " -o "+output_dir_field.text

    switch(analysis_type.currentIndex){

        case 0:
            worker_opts += " -i "+output_dir_field.text+"/ip.pcap"
            break;
        case 1:
            worker_opts += " -i "+output_dir_field.text+"/sip-ip.pcap"
            break;
        case 2:
            worker_opts += " -i "+output_dir_field.text+"/tcp-ip.pcap"
            break;
        case 3:
            worker_opts += " -i "+output_dir_field.text+"/dns.pcap"
            break;

        default:
            log_output.text = "Unknown option"
            return false
    }

    return worker_cmd + worker_opts
}

function run_filter(){
    /*
      Function checkes whether filter is necessary to run
    */

    switch(analysis_type.currentIndex){

        case 0:
            filtered_file = output_dir_field.text+"/ip.pcap"
            break;
        case 1:
            filtered_file = output_dir_field.text+"/sip-ip.pcap"
            break;
        case 2:
            filtered_file = output_dir_field.text+"/tcp-ip.pcap"
            break;
        case 3:
            filtered_file = output_dir_field.text+"/dns.pcap"
            break;

        default:
            log_output.text = "Unknown option"
            return false
    }

    return 1
}
