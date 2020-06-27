package com.springbook.view.user;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.springbook.biz.user.UserVO;
import com.springbook.biz.user.impl.UserDAO;
import com.springbook.view.controller.Controller;

public class LoginController implements Controller {

	@Override
	public String handleRequest(HttpServletRequest request, HttpServletResponse response) {
		System.out.println("�α��� ó��");

		// 1. ����� �Է� ���� ����
		// ����ڰ� �Է��� ���̵�� ��й�ȣ�� request ��ü�κ��� �����Ѵ�.
		// �׸��� Model�� �ش��ϴ� UserVO�� UserDAO ��ü�� �̿��Ͽ� ����� ������ �˻��Ѵ�.
		// �׸��� �˻������ UserVO ��ü�� ���ϵǸ� �α��� ����, null�� ���ϵǸ� �α��� ���з� ó��
		String id = request.getParameter("id");
		String password = request.getParameter("password");

		// 2. DB ���� ó��
		UserVO vo = new UserVO();
		vo.setId(id);
		vo.setPassword(password);

		UserDAO userDAO = new UserDAO();
		UserVO user = userDAO.getUser(vo);

		// 3. ȭ�� �׺���̼�
		// ȭ�� �׺���̼� ������� ������(Forward)��İ� �����̷�Ʈ(Redirect) �� ���� ����� �ִ�.
		// �ڼ��� ������ ���� 248p ����
		if (user != null) {
			return "getBoardList.do";
		} else {
			// Ȯ���� ���� ���ڿ��� �����ϸ� �ڵ����� '.jsp' Ȯ���ڰ� �پ ó���ȴ�.
			return "login";
		}
	}

}
