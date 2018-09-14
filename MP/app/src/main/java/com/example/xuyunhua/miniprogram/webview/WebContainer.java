package com.example.xuyunhua.miniprogram.webview;

import android.annotation.TargetApi;
import android.content.Context;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.webkit.WebResourceRequest;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.widget.FrameLayout;

import java.util.HashMap;

public class WebContainer {

    private WebView webcore;
    private Bridger bridger;
    private String mimeType;
    private HashMap<String,String>h_head_;

    public WebContainer(Context context){
        initWebView(context);
        bridger = new Bridger(this);
    }

    private  void initWebView(Context context){
        webcore = new WebView(context);
        FrameLayout.LayoutParams layoutParams = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT);
        webcore.setLayoutParams(layoutParams);
        WebSettings _websets = webcore.getSettings();
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP){
            _websets.setMixedContentMode(WebSettings.MIXED_CONTENT_COMPATIBILITY_MODE);
        }
        _websets.setJavaScriptEnabled(true);
        webcore.addJavascriptInterface(new WebExcutor(bridger),"__POST__");
    }

    public void load(String data){
        webcore.loadData(data,"text/html","UTF-8");
    }

    public void loadRequest(String url){
        loadRequest(url,null);
    }

    public void loadRequest(String url, HashMap<String,String>httpHead){
        webcore.loadUrl(url,httpHead);
    }

    public WebView getView(){
        return this.webcore;
    }

    public void invoke(String message){
        if(bridger != null){
            bridger.invoke(message);
        }
    }

    public boolean client_call(WebResourceRequest request){
        return false;

    }

    public void clear_js_interface(){
        if(webcore == null)return;
        if(Build.VERSION.SDK_INT>=11 && Build.VERSION.SDK_INT<=17){
            webcore.removeJavascriptInterface("__POST__");
        }
    }



}
