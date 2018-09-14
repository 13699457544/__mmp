package com.example.xuyunhua.miniprogram.webview;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.EventListener;

public class Bridger {

    private WebContainer cantainer_;

    public Bridger(WebContainer container){
        if(container !=null){
            this.cantainer_ = container;
        }
    }

    public void invoke(String str) {
        if(str == null)return;
        try {
            JSONObject jsonObject = new JSONObject(str);
            String event = jsonObject.optString("EVENT_TYPE");
            int handler = jsonObject.optInt("ID");
            JSONObject message = jsonObject.optJSONObject("message");
            if(event.length()<1 || message == null) return;
            dispatchEvent(event,handler,message);
        } catch (JSONException e) {
            e.printStackTrace();
            return;
        }
    }

    public void dispatchEvent(String event,int handler,JSONObject message){
        iCallback callback = new BridgeCallback(this.cantainer_,handler);
        DispatchAgent agent = DispatchAgent.getInstance();
        if(agent == null)return;
        iInvoke EVENT_FUNC = agent.obtainEventFunc(event);
        if(EVENT_FUNC == null || message == null)return;
        EVENT_FUNC.invoke(this.cantainer_,message,callback);

    }
}
