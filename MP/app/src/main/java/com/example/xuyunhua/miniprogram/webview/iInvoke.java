package com.example.xuyunhua.miniprogram.webview;

import org.json.JSONObject;

import java.util.HashMap;

public interface iInvoke {
    void invoke(WebContainer container, JSONObject data, iCallback callback);
}
