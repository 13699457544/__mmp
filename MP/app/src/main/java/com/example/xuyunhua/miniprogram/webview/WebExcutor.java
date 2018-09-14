package com.example.xuyunhua.miniprogram.webview;

import android.support.annotation.RequiresApi;
import android.webkit.JavascriptInterface;

public class WebExcutor {
    private Bridger bridger_;
    public WebExcutor(Bridger bridger){
        this.bridger_ = bridger;
    }
    @RequiresApi(17)
    @JavascriptInterface
    public void post(String message){
        if(bridger_ == null || message == null) return;
        bridger_.invoke(message);
    }
}
