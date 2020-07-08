package com.springbook.view.user;

import javax.servlet.http.HttpSession;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;

//import org.springframework.web.servlet.ModelAndView;
//import org.springframework.web.servlet.mvc.Controller;

import com.springbook.biz.user.UserVO;
import com.springbook.biz.user.impl.UserDAO;

/*
public class LoginController implements Controller {
	
	@Override
	public ModelAndView handleRequest(HttpServletRequest request, HttpServletResponse response) {
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
		
		// "redirect:" �� �ִٸ� ViewResolver(presentation-layer.xml ����)�� �����Ǿ� �ִ��� �̸� �����ϰ� �����̷�Ʈ�Ѵ�.
		ModelAndView mav = new ModelAndView();
		if (user != null) {
			mav.setViewName("redirect:getBoardList.do");
		} else {
			mav.setViewName("redirect:login.jsp");
		}
		return mav;
	}

}
*/

// ������̼� ���
@Controller
public class LoginController {
	// RequestMappring�� method�� �߰��Ͽ� ���� �ٸ� �޼ҵ庰�� ó���ǰ� �� �� �ִ�.
	@RequestMapping(value="/login.do", method=RequestMethod.GET)
	public String loginView(UserVO vo)
	{
		System.out.println("�α��� ȭ������ �̵�");
		// UserVO ��ü�� login.jsp���� ����Ѵ�.
		// ���� .jsp ���Ͽ��� �̸��� UserVO�� �ƴ� �ٸ� �̸����� �����ϰ� �ʹٸ�
		// public String loginView(@ModelAttribute("user") UserVO vo) �� �����ϸ� �ȴ�.
		vo.setId("test");
		vo.setPassword("test123");
		return "login.jsp";
	}
	
	@RequestMapping(value="/login.do", method=RequestMethod.POST)
	public String login(UserVO vo, UserDAO userDAO, HttpSession session) {
		System.out.println("�α��� ó��");
		
		if (vo.getId() == null || vo.getId().equals("")) {
			throw new IllegalArgumentException("���̵�� �ݵ�� �Է��ؾ� �մϴ�.");
		}
		
		UserVO user = userDAO.getUser(vo);
		
		if (userDAO.getUser(vo) != null)
		{
			session.setAttribute("userName", user.getName());
			return "getBoardList.do";
		}
		else
		{
			return "login.jsp";
		}
	}

}