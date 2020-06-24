package com.springbook.biz.user;

public class UserVO {
	
	private String id;
	private String password;
	private String name;
	private String rolo;
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getRolo() {
		return rolo;
	}
	public void setRolo(String rolo) {
		this.rolo = rolo;
	}
	
	@Override
	public String toString() {
		return "UserVO [id=" + id + ", password=" + password + ", name=" + name + ", rolo=" + rolo + "]";
	}
	
	

}
