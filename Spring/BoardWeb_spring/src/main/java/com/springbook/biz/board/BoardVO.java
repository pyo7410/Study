package com.springbook.biz.board;

//import java.sql.Date;
// XML�� ��ȯ�ҷ��� �ݵ�� �ش� Ŭ������ �⺻ �����ڰ� �־���ϹǷ� java.util.Date�� �ʿ�
import java.util.Date;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlTransient;

import org.springframework.web.multipart.MultipartFile;

import com.fasterxml.jackson.annotation.JsonIgnore;

// Value Object
// @XmlAccessorType ������̼��� �ش� ��ü�� XML�� ��ȯ�� �� �ִٴ� �ǹ�
// XmlAccessType.FIELD ������ �� ��ü�� ���� �ʵ�, �� �������� �ڵ����� �ڽ� ������Ʈ�� ǥ���ȴ�.
// ������ @XmlAttribute�� ���� ������ �ڽ� ������Ʈ���ƴ� �Ӽ����� ǥ���϶�� �ǹ��̴�.
// @XmlTransient�� JSON���� @JsonIgnore�� ���� ������ ������̼� �̴�.
@XmlAccessorType(XmlAccessType.FIELD)
public class BoardVO {
	@XmlAttribute
	private int seq;
	private String title;
	private String writer;
	private String content;
	private Date regDate;
	private int cnt;
	@XmlTransient
	private String searchCondition;
	@XmlTransient
	private String searchKeyword;
	@XmlTransient
	private MultipartFile uploadFile;
	public int getSeq() {
		return seq;
	}
	public void setSeq(int seq) {
		this.seq = seq;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getWriter() {
		return writer;
	}
	public void setWriter(String writer) {
		this.writer = writer;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public Date getRegDate() {
		return regDate;
	}
	public void setRegDate(Date regDate) {
		this.regDate = regDate;
	}
	public int getCnt() {
		return cnt;
	}
	public void setCnt(int cnt) {
		this.cnt = cnt;
	}
	// @JsonIgnore ������̼��� �ڹ� ��ü�� JSON ���� ��ȯ�� ��, Ư�� ������ ��ȯ���� ���� ��Ų��.
	// @JsonIgnore�� Getter �޼ҵ����� �����ؾ����� ����
	@JsonIgnore
	public String getSearchCondition() {
		return searchCondition;
	}
	public void setSearchCondition(String searchCondition) {
		this.searchCondition = searchCondition;
	}
	@JsonIgnore
	public String getSearchKeyword() {
		return searchKeyword;
	}
	public void setSearchKeyword(String searchKeyword) {
		this.searchKeyword = searchKeyword;
	}
	@JsonIgnore
	public MultipartFile getUploadFile() {
		return uploadFile;
	}
	public void setUploadFile(MultipartFile uploadFile) {
		this.uploadFile = uploadFile;
	}
	
	@Override
	public String toString() {
		return "BoardVO [seq=" + seq + ", title=" + title + ", writer=" + writer + ", content=" + content + ", regDate="
				+ regDate + ", cnt=" + cnt + ", searchCondition=" + searchCondition + ", searchKeyword=" + searchKeyword
				+ ", uploadFile=" + uploadFile + "]";
	}
}
