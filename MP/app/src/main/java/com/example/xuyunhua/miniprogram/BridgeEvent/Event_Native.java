package com.example.xuyunhua.miniprogram.BridgeEvent;

import com.example.xuyunhua.miniprogram.NativeCall.NativeDispatch;
import com.example.xuyunhua.miniprogram.webview.DispatchAgent;
import com.example.xuyunhua.miniprogram.webview.WebContainer;
import com.example.xuyunhua.miniprogram.webview.iCallback;
import com.example.xuyunhua.miniprogram.webview.iInvoke;

import org.json.JSONObject;

public class Event_Native {
    DispatchAgent agent = DispatchAgent.getInstance();
    public void load(){
        agent.registerEvent("EVENT_NATIVE", new iInvoke() {
            @Override
            public void invoke(WebContainer container, JSONObject data, iCallback callback) {
                NativeDispatch.Builder builder = new NativeDispatch.Builder();
                builder.setWebContainer(container).setEevent("EVENT_NATIVE").setJosonObject(data);
                NativeDispatch dispatch = builder.build();
                dispatch.exctuor();
            }
        });
    }
}
