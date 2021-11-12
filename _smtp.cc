int STMP::addln_context(auto ln){
    //TODO !!! setup proper limit function HERE---------------------!!!
    if(ln.size() > def_max_sz) 
        return -1;

    itel++;
    context_ln.push_back(ln);
    return 0;
}

int STMP::craft_context(string subject){
    //TODO !!! setup proper limit function HERE---------------------!!!
    if(subject.size() > def_max_sz)
        return -1;

    //seting up header & plain textencoding for now
    msg.subject(subject);
    msg.content_transfer_encoding(mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
    msg.content_type(message::media_type_t::TEXT, "plain", "utf-8");

    //adding lines to prepare main body of message
    //msgu8 contracated from context vector
    for(int itel = 0 ; i <= context_ln.size(); i++)
        this->msgu8 += context_ln[itel];
    return 0;
}