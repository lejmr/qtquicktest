function filter_cmd() {
    /*
      Function composes filter command based on app options
    */

    var filter_cmd = "./filter"
    var filter_input_files = input_file_command.text.replace(/file:\/\//g,"")
    var filter_output_dir = output_dir_field.text.replace(/file:\/\//g,"")
    var filter_opts = filter_input_files + " -o " + filter_output_dir

    if( size_field.text > 0 )
        filter_opts += " -s "+size_field.text

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
    var filter_output_dir = output_dir_field.text.replace(/file:\/\//g,"")

    var worker_cmd = "./savesip"
    var worker_opts = " -o " + filter_output_dir

    switch(analysis_type.currentIndex){

        case 0:
            worker_opts += " -i "+filter_output_dir+"/ip.pcap"
            break;
        case 1:
            worker_opts += " -i "+filter_output_dir+"/sip-ip.pcap"
            break;
        case 2:
            worker_opts += " -i "+filter_output_dir+"/tcp-ip.pcap"
            break;
        case 3:
            worker_opts += " -i "+filter_output_dir+"/dns.pcap"
            break;

        default:
            log_output.text = "Unknown option"
            return false
    }

    return worker_cmd + worker_opts
}

function filter_output(){
    /*
      Function checkes whether filter is necessary to run
    */
    var filtered_file = "";
    var filter_output_dir = output_dir_field.text.replace(/file:\/\//g,"")
    switch(analysis_type.currentIndex){

        case 0:
            filtered_file = filter_output_dir+"/ip.pcap"
            break;
        case 1:
            filtered_file = filter_output_dir+"/sip-ip.pcap"
            break;
        case 2:
            filtered_file = filter_output_dir+"/tcp-ip.pcap"
            break;
        case 3:
            filtered_file = filter_output_dir+"/dns.pcap"
            break;

        default:
            log_output.text = "Unknown option"
            return false
    }

    return filtered_file
}
