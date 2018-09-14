package com.example.xuyunhua.miniprogram.webview;

import org.json.JSONObject;

public class BridgeCallback implements iCallback {
    private WebContainer container_;
    private int handler_;
    public BridgeCallback(WebContainer container,int handler){
        container_ = container;
        handler_ = handler;
    }
    @Override
    public void call(JSONObject result) {

    }

    @Override
    public void call() {

    }
}
