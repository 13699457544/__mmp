package com.example.xuyunhua.miniprogram.NativeCall;

import com.example.xuyunhua.miniprogram.webview.WebContainer;

import org.json.JSONObject;


public class NativeDispatch implements Exctuor,n_call{
    private WebContainer container_;
    private String event;
    private JSONObject object;

    private NativeDispatch(Builder builder){
        container_ = builder.container_;
        event = builder.event;
        object = builder.object;
    }

    @Override
    public void exctuor() {
        if(event == null)return;
        executor(event,object,this);
    }

    @Override
    public void onSucess(String message) {

    }

    @Override
    public void onFail(String error) {

    }

    @Override
    public void onComplete(String info) {

    }

  public static class Builder{
        private WebContainer container_;
        private String event;
        private JSONObject object;

        public Builder setWebContainer(WebContainer container){
            container_ = container;
            return this;
        }

        public Builder setEevent(String e_ty){
            event = e_ty;
            return this;
        }

        public Builder setJosonObject(JSONObject o_json){
            object = o_json;
            return this;
        }

        public NativeDispatch build(){
            return new NativeDispatch(this);
        }
    }

    public native boolean executor (String event, JSONObject object, n_call call);
}
